#pragma once

#include "ICurveEditorModule.h"

class FCurveEditor;
class FPaintArgs;
class FSlateRect;
class FSlateWindowElementList;
class FText;
class FWidgetStyle;
struct FGeometry;

class TTSCurveEditorModule : public SInteractiveCurveEditorView
/**
 * @class TTSCurveEditorModule
 * The TTSCurveEditorModule class is responsible for constructing and painting a curve editor view for the TTSCurveEditor module.
 * It implements the ICurveEditorModule interface and provides functionality for constructing the view, getting grid lines, ticking, computing desired size, and painting the view.
 */
{
public:
	/**
	@details Construct the TTSCurveEditorModule
	@brief Construct the TTSCurveEditorModule
	@param InArgs The arguments to construct the TTSCurveEditorModule
	@param InCurveEditor The curve editor to construct the TTSCurveEditorModule
	@returns void */
	void Construct(const FArguments& InArgs, TWeakPtr<FCurveEditor> InCurveEditor) {
		ICurveEditorModule& TTSCurveEditorModule = FModuleManager::LoadModuleChecked<ICurveEditorModule>("TTSCurveEditor");

		/*TSharedRef<FCurveEditor>*/ CurveEditor = TTSCurveEditorModule.CreateCurveEditor();

		// Configure grid line style
		FCurveEditorGridLineSettings GridLineSettings;
		GridLineSettings.bSnapEnabled = false;  // Enable snapping for precise control
		GridLineSettings.GridLineThickness = 1.0f;  // Thickness of the grid lines
		GridLineSettings.bDrawSecondary = true;  // Draw secondary grid lines for more granularity

		// Set grid line settings to the Curve Editor
		CurveEditor->GridLineSettings = GridLineSettings;

		// Configure Labels for Frequency and Amplitude
		// Assume X-axis is time, Y-axis is frequency, and each curve's value represents amplitude

		// Configure axis title labels
		CurveEditor->GetAxisTitle(EAxisList::Y)->SetText(FText::FromString(TEXT("Frequency (Hz)")));
		CurveEditor->GetAxisTitle(EAxisList::X)->SetText(FText::FromString(TEXT("Frames")));

		// Configure axis label numbers for frequency (you may want to scale these based on your specific data range)
		CurveEditor->GetGridLineLabel(EAxisList::Y)->SetFixedLineSpacing(1000.0f);  // Space between lines in Hz
		CurveEditor->GetGridLineLabel(EAxisList::X)->SetFixedLineSpacing(1.0f);  // Space between lines in frames or seconds for timefor (int32 FormantIndex = 0; FormantIndex < NumberOfFormants; ++FormantIndex)


		// Costumize the curve editor appearance
		for (int32 FormantIndex = 0; FormantIndex < NumberOfFormants; ++FormantIndex) {
			TSharedPtr<FCurveModel> MyFormantCurveModel;  // You need to create and configure your curve model based on your data

			// Customize curve color
			FLinearColor CurveColor = FLinearColor::MakeRandomColor();
			CurveEditor->GetCurveEditor()->GetCurveView(Model->GetID())->SetColor(CurveColor);
			
			// Add the curve model to the editor
			CurveEditor->AddCurve(MyFormantCurveModel.ToSharedRef());
		}


		// Other customizations
		// Example: Set initial view range (customize this based on your typical data range)
		CurveEditor->SetInputViewRange(0.f, 1.f);  // 10 seconds view
		CurveEditor->SetOutputViewRange(20.f, 500.f);  // Up to 5000 Hz


		// Dsplay the curve editor

		/*
		TTSCurveEditorModule::ViewID = TTSCurveEditorModule.RegisterView(FOnCreateCurveEditorView::CreateStatic(
			[](TWeakPtr<FCurveEditor> WeakCurveEditor) -> TSharedRef<SCurveEditorView>
			{
				return SNew(TTSCurveEditorView, WeakCurveEditor);
			}
		));
		*/
	
		// Define the tab identifier and the tab label
		const FName TabIdentifier = FName(TEXT("MyCurveEditorTab"));
		const FText TabLabel = FText::FromString(TEXT("TTS Formant Curve Editor"));

		// Register the new tab spawner
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TabIdentifier, FOnSpawnTab::CreateLambda([this](const FSpawnTabArgs& SpawnTabArgs) {
			// Create the SWidget that hosts the Curve Editor
			return SNew(SDockTab)
				.Label(TabLabel)
				.TabRole(ETabRole::NomadTab)
				[
					SNew(SBorder)
					.Padding(4)
					[
						// Assuming CurveEditor is your TSharedRef<FCurveEditor>
						CurveEditor->MakeWidget()
					]
				];
		})).SetDisplayName(TabLabel);

		// Display the new tab
		FGlobalTabmanager::Get()->TryInvokeTab(TabIdentifier);


	   
	};

	/**
	@details Get the grid lines for the curve editor view
	@brief Get the grid lines for the curve editor view
	@param CurveEditor The curve editor to get the grid lines for
	@param MajorGridLines The major grid lines for the curve editor view
	@param MinorGridLines The minor grid lines for the curve editor view
	@param MajorGridLabels The major grid labels for the curve editor view
	@returns void */
	virtual void GetGridLinesY(TSharedRef<const FCurveEditor> CurveEditor
		, TArray<float>& MajorGridLines
		, TArray<float>& MinorGridLines
		, TArray<FText>* MajorGridLabels) const override {};

private:


	static ECurveEditorViewID ViewID; 
	
	// Smart pointer to manage the Curve Editor instance
	TSharedPtr<FCurveEditor> CurveEditor;

	// SWidget Interface
	/**
	@details Tick the curve editor view
	@brief Tick the curve editor view
	@param AllottedGeometry The geometry of the curve editor view
	@param InCurrentTime The current time of the curve editor view
	@param InDeltaTime The delta time of the curve editor view
	@returns void */
	virtual void Tick(const FGeometry& AllottedGeometry
		, const double InCurrentTime
		, const float InDeltaTime) override {
			TSharedPtr<FCurveEditor> CurveEditor = WeakCurveEditor.Pin();
			if (!CurveEditor)
			{
				return;
			}

			double Count = 0.0;
			for (auto It = CurveInfoByID.CreateIterator(); It; ++It)
			{
				FCurveModel* Curve = CurveEditor->FindCurve(It.Key());
				if (ensureAlways(Curve))
				{
					It->Value.ViewToCurveTransform = FTransform2D(FVector2D(0.f, Count));
				}

				Count += 1.0;
			}

			OutputMin = OutputMax - FMath::Max(Count, 1e-10);
			SInteractiveCurveEditorView::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
	};

	/**
	@details Compute the desired size of the curve editor view
	@brief Compute the desired size of the curve editor view
	@param LayoutScaleMultiplier The layout scale multiplier of the curve editor view
	@returns void */
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override {};

	// SInteractiveCurveEditorView interface
	/**
	@details Paint the curve editor view
	@brief Paint the curve editor view
	@param Args The paint arguments of the curve editor view
	@param AllottedGeometry The geometry of the curve editor view
	@param MyCullingRect The culling rectangle of the curve editor view
	@param OutDrawElements The draw elements of the curve editor view
	@param BaseLayerId The base layer ID of the curve editor view
	@param InWidgetStyle The widget style of the curve editor view
	@param bParentEnabled The parent enabled state of the curve editor view
	@returns void */
	virtual void PaintView(const FPaintArgs& Args
		, const FGeometry& AllottedGeometry
		, const FSlateRect& MyCullingRect
		, FSlateWindowElementList& OutDrawElements
		, int32 BaseLayerId
		, const FWidgetStyle& InWidgetStyle
		, bool bParentEnabled) const override {
			TSharedPtr<FCurveEditor> CurveEditor = WeakCurveEditor.Pin();
			if (CurveEditor)
			{
				const ESlateDrawEffect DrawEffects = ShouldBeEnabled(bParentEnabled) ? ESlateDrawEffect::None : ESlateDrawEffect::DisabledEffect;

				DrawBackground(AllottedGeometry
					, OutDrawElements
					, BaseLayerId
					, DrawEffects);
				DrawLabels(AllottedGeometry
					, OutDrawElements
					, BaseLayerId
					, DrawEffects);
				DrawGridLines(CurveEditor.ToSharedRef()
					, AllottedGeometry
					, OutDrawElements
					, BaseLayerId
					, DrawEffects);
				DrawCurves(CurveEditor.ToSharedRef()
					, AllottedGeometry
					, MyCullingRect
					, OutDrawElements
					, BaseLayerId
					, InWidgetStyle
					, DrawEffects);
			}
	};

	/**
	@details Determine if value snap is enabled for the curve editor view
	@brief Determine if value snap is enabled for the curve editor view
	@returns void */
	virtual bool IsValueSnapEnabled() const override { return false; }

	/**
	@details Draw the labels of the curve editor view
	@brief Draw the labels of the curve editor view
	@param AllottedGeometry The geometry of the curve editor view
	@param OutDrawElements The draw elements of the curve editor view
	@param BaseLayerId The base layer ID of the curve editor view
	@param DrawEffects The draw effects of the curve editor view
	@returns void */
	void DrawLabels(const FGeometry& AllottedGeometry
		, FSlateWindowElementList& OutDrawElements
		, int32 BaseLayerId
		, ESlateDrawEffect DrawEffects) const {
			TSharedPtr<FCurveEditor> CurveEditor = WeakCurveEditor.Pin();
			if (!CurveEditor)
			{
				return;
			}

			const FSlateBrush* WhiteBrush = FAppStyle::GetBrush("WhiteBrush");

			// Draw some text telling the user how to get retime anchors.
			const FSlateFontInfo FontInfo = FCoreStyle::Get().GetFontStyle("ToolTip.LargerFont");

			// We have to measure the string so we can draw it centered on the window.
			const TSharedRef<FSlateFontMeasure> FontMeasure = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();

			const FVector2D LocalSize = AllottedGeometry.GetLocalSize();

			const FCurveEditorScreenSpaceV ViewSpace = GetViewSpace();

			for (auto It = CurveInfoByID.CreateConstIterator(); It; ++It)
			{
				FCurveModel* Curve = CurveEditor->FindCurve(It.Key());
				if (!ensureAlways(Curve))
				{
					continue;
				}

				const int32 CurveIndex = static_cast<int32>(It->Value.ViewToCurveTransform.GetTranslation().Y);

				const FCurveEditorScreenSpaceV CurveSpace = ViewSpace.ToCurveSpace(It->Value.ViewToCurveTransform);
				const float LaneTop = CurveSpace.ValueToScreen(0.0) - TrackHeight*.5f;

				// Draw the curve color as the background. Event curves set their track color as the curve color.
				FLinearColor CurveColor = Curve->GetColor();

				// Alpha blend the zebra tint
				if (CurveIndex%2)
				{
					static FLinearColor ZebraTint = FLinearColor::White.CopyWithNewOpacity(0.01f);
					if (CurveColor == FLinearColor::White)
					{
						CurveColor = ZebraTint;
					}
					else
					{
						CurveColor = CurveColor * (1.f - ZebraTint.A) + ZebraTint * ZebraTint.A;
					}
				}

				if (CurveColor != FLinearColor::White)
				{
					const FPaintGeometry BoxGeometry = AllottedGeometry.ToPaintGeometry(
						FVector2D(AllottedGeometry.GetLocalSize().X, TrackHeight),
						FSlateLayoutTransform(FVector2D(0.f, LaneTop))
					);

					FSlateDrawElement::MakeBox(OutDrawElements, BaseLayerId + CurveViewConstants::ELayerOffset::Background, BoxGeometry, WhiteBrush, DrawEffects, CurveColor);
				}

				// Draw the curve label
				{
					const FText Label = Curve->GetLongDisplayName();

					const FVector2D TextSize = FontMeasure->Measure(Label, FontInfo);
					const FVector2D Position(LocalSize.X - TextSize.X - CurveViewConstants::CurveLabelOffsetX, LaneTop + (TrackHeight - TextSize.Y)*.5f);

					const FPaintGeometry LabelGeometry = AllottedGeometry.ToPaintGeometry(
						FSlateLayoutTransform(Position)
					);

					FSlateDrawElement::MakeText(OutDrawElements, BaseLayerId + CurveViewConstants::ELayerOffset::Labels, LabelGeometry, Label, FontInfo, DrawEffects, FLinearColor::White);
				}
			}
	};


	static float TrackHeight;
};

/**
@fn FReply OnMyBlueprintSingleClicked(YourCustomBlueprintType* ClickedBlueprint)
@details Respond to a single click on a custom blueprint
@brief Respond to a single click on a custom blueprint
@param InMyGeometry The geometry of the custom blueprint
@param InMouseEvent The mouse event of the custom blueprint
@param ClickedBlueprint The custom blueprint that was clicked
@returns FReply */
FReply OnMyBlueprintDoubleClicked(const FGeometry& InMyGeometry
	, const FPointerEvent& InMouseEvent
	, YourCustomBlueprintType* ClickedBlueprint) {
		if (ClickedBlueprint)
		{
			// Handle the double-click event, possibly opening a Curve Editor
			// or performing other actions specific to the double-clicked Blueprint
		}

		return FReply::Handled();
};

// Register the custom Curve Editor tabview
virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override {
	FAssetEditorToolkit::RegisterTabSpawners(TabManager);

	TabManager->RegisterTabSpawner(TabIdentifier, FOnSpawnTab::CreateSP(this, &FMyCustomAssetEditor::SpawnTab))
		.SetDisplayName(TabLabel)
		.SetGroup(GroupName);
};

// Add toolbars
// Assuming 'MyBlueprintItemWidget' is a UI element representing an instance of your custom Blueprint
void FMyCustomAssetEditor::SpawnTab(const FSpawnTabArgs& Args) {
	const TSharedRef< FUICommandList > CommandList = MakeShared<FUICommandList>();

	// Create the toolbar and add buttons
	FToolBarBuilder ToolBarBuilder(CommandList, FMultiBoxCustomization::None);
	ToolBarBuilder.AddToolBarButton(
		FUIAction(FExecuteAction::CreateLambda([]() { /* Your button action code here */ })),
		NAME_None,
		TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateLambda([]() { return FText::FromString("Button Label"); })),
		TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateLambda([]() { return FText::FromString("Tooltip Text"); }))
	);
	// Add more buttons as needed

	// Create the final widget
	TSharedPtr<SWidget> ToolbarWidget = ToolBarBuilder.MakeWidget();
	// Use ToolbarWidget in your tab layout
};


// Add tooltips
SNew(STextBlock)
.Text(FText::FromString("This is a text block"))
.ToolTipText(FText::FromString("This is a tooltip for the text block"));


//  Add Push Buttons
SNew(SButton)
.Text(FText::FromString("Click Me"))
.ToolTipText(FText::FromString("Click this button to perform an action"))
.OnClicked_Lambda([]()
{
    // Define what happens when the button is clicked
    return FReply::Handled();
});

// Combine Elements in the Tab Layout
SNew(SDockTab)
.Label(TabLabel)
[
	SNew(SHorizontalBox)
	+ SVerticalBox::Slot()
	.AutoHeight()
	[
		ToolbarWidget.ToSharedRef()
	]
	+ SHorizontalBox::Slot()
	.FillHeight(1.0f)
	.Padding(4)
	[
		// Your main content here
	]
	// Add more elements as needed
]




