#pragma once

#include <algorithm> // For std::clamp
#include <string>
#include <cmath> // for std::round
#include <cstdint>  // For std::uint32_t
#include <bitset>   // For std::bitset if needed
#include <vector>
#include <map>
#include <variant>
#include <functional>
#include <format>
#include <optional>

namespace TTSCurveEditorNamespace {

    namespace ChartJS {

        enum class AxisType {
            linear,
            logarithmic,
            // ... add other types as needed
        };

        enum class YAxisPosition {
            left,
            right
            // ... add other positions as needed
        };

        enum class XAxisPosition {
            top,
            bottom
            // ... add other positions as needed
        };

        enum class LegendPosition {
            top,
            bottom,
            left,
            right
            // ... add other positions as needed
        };

        struct RGB {
            uint32_t red;
            uint32_t green;
            uint32_t blue;
        };

        struct RGBA {
            uint32_t red;
            uint32_t green;
            uint32_t blue;
            double alpha;
        };

        struct AxisGrid {
            bool drawOnChartArea;
        };

        struct AxisTicks {
            std::function<std::string(long long int, long long int, const std::vector<>&)> callback;
        };

        template<typename StringType = std::string>
        struct AxisTitle {
            StringType axisID;
            StringType text;
            bool display;
        };

        template<typename T>
        struct YAxis {
            std::string axisID;
            AxisType type;
            AxisTitle<T> title;
            bool display;
            YAxisPosition position;
            AxisGrid grid;
            AxisTicks ticks;
        };

        template<typename T>
        struct XAxis {
            std::string axisID;
            AxisType type;
            AxisTitle<T> title;
            bool display;
            XAxisPosition position;
            AxisGrid grid;
            AxisTicks ticks;
        };

        struct LegendLabels {
            RGBA fontColor;
            int fontSize;
            int boxWidth;
            int padding;
            bool usePointStyle;
            bool useLineStyle;
            bool useColor;
            bool display;
            LegendPosition position;
        };

        struct Legend {
            LegendLabels labels;
            bool display;
            LegendPosition position;
        };

        struct CrosshairLine {
            RGBA color;
            int width;
            std::vector<int> dashPattern;
        };

        struct Crosshair {
            bool enabled;
            CrosshairLine line;
        };

        struct TooltipCallbacks {
            std::function<std::string(const std::vector<>&, const std::vector<>&)> title;
            std::function<std::string(const std::variant<int, std::string>&, const std::vector<>&)> label;
        };

        struct Tooltip {
            bool enabled;
            std::string mode;
            std::string position;
            int bodyFontSize;
            TooltipCallbacks callbacks;
        };

        struct Plugins {
            Legend legend;
            Crosshair crosshair;
            Tooltip tooltip;
        };

        template<typename T = std::string>
        struct Scales {
            std::vector<YAxis<T>> yAxes;
            std::vector<XAxis<T>> xAxes;
        };

        template<typename T>
        struct ChartType {
            T type;
        };

        template<typename T>
        struct Dataset {
            std::string label;
            std::vector<T> data;
            std::string borderColor;
            RGB backgroundColor;
            std::string yAxisID;
            std::string xAxisID;
        };

        template<typename T>
        struct Data {
            std::vector<Dataset<T>> datasets;
        };

        struct Options {
            Scales<> scales;
            Plugins plugins;
        };

        enum class windowEvent {
            mousemove,
            click
            // ... add other events as needed
        };

        struct Event {
            // Event data
        };

        struct AddEventListener {
            windowEvent windowEvent;
            void* m_hWnd;
            std::function<void(const Event&)> callback;
        };

        struct ChartArea {
            float left;
            float right;
            float top;
            float bottom;
        };

        struct Scale {
            // Assuming these functions exist in your actual implementation
            float getValueForPixel(float pixel) const {
                // Implementation
            }

            float left;
            float right;
            float top;
            float bottom;
        };

        using PointPrecision = std::variant<long double, unsigned long long int>;
        using param1 = PointPrecision;
        using param2 = PointPrecision;
        template <typename param1 = long double, typename param2 = unsigned long long int>
        class Point {
        public:
            PointPrecision x;
            PointPrecision y;

            void Constructor(const param1 x = 0.0f, const param2 y = 0) {
                this->x = x;
                this->y = y;
            };
        };

        class Chart {
        public:
            Chart() = default;
                
            // Assuming these members exist in your actual implementation
            Point<> crosshair;
            ChartArea chartArea;
            Scale scales[2]; // x-axis-frame and y-axis-amplitude/frequency
            bool yAxisAmplitudeVisibleFlag;
            gl::Context ctx;

            // ... other members and functions

            void setConfig(const std::string& key, const std::variant<ChartType<std::string>, Data<std::string>, Options>& value) {
                // Set configuration based on key-value pairs
            }

            void addEventListener(const AddEventListener& listener) {
                // Add event listener
            }

            // Optionally, define functions like plotAmplitudes, plotFrequencies if needed
            void Constructor(Chart& chart) {
                // Implementation
            }

        private:
            // Internal representation of the chart configuration
            std::unordered_map<std::string, std::variant<ChartType<std::string>, Data<std::string>, Options>> config;
            std::vector<AddEventListener> eventListeners;
        }; // Chart class

        namespace CustomPlugin {
            class beforeDatasetsDrawHandler {
                std::string id;
                std::function<void(Chart&)> beforeDatasetsDraw = [](Chart& chart) -> void { };
            };
            class afterDatasetsDrawHandler {
                std::string id;
                std::function<void(Chart&)> afterDatasetsDraw = [](Chart& chart) -> void { };
            };
        }

        // Registering the plugin - You would need to adapt this to match how your C++ Chart class handles plugins
        void registerPlugin(CustomPlugin::beforeDatasetsDrawHandler& plugin) {
            // Implementation for registering the plugin to the Chart
            // This might involve adding the plugin to a list, setting up callbacks, etc.
        }

        // Registering the plugin - You would need to adapt this to match how your C++ Chart class handles plugins
        void registerPlugin(CustomPlugin::afterDatasetsDrawHandler& plugin) {
            // Implementation for registering the plugin to the Chart
            // This might involve adding the plugin to a list, setting up callbacks, etc.
        }

    }  // ChartJS namespace

    //extern Chart g_formantChart; // Global Chart object

    void updateCrossHair(float mouseX, float mouseY) {
        // Assuming Chart class has a method to update crosshair position
        g_formantChart.updateCrosshairPosition(mouseX, mouseY);
        g_formantChart.update();
    }

    // WaveShape enum class equivalent
    enum class WaveShape : std::uint32_t {
        Sine_enum = 1 << 0,
        Cosine_enum = 1 << 1,
        QuarterSine_enum = 1 << 2,
        HalfSine_enum = 1 << 3,
        Triangle_enum = 1 << 4,
        Square_enum = 1 << 5,
        ForwardSawtooth_enum = 1 << 6,
        ReverseSawtooth_enum = 1 << 7,
        WhiteNoise_enum = 1 << 8,
        BrownNoise_enum = 1 << 9,
        PinkNoise_enum = 1 << 10,
        YellowNoise_enum = 1 << 11,
        BlueNoise_enum = 1 << 12,
        GreyNoise_enum = 1 << 13,
        WhiteGaussianNoise_enum = 1 << 14,
        PurpleVioletNoise_enum = 1 << 15
    };

    // Assuming borderColor is a member of the Chart class
    void setDefaults() {
        g_formantChart.borderColor = "#444"; // You would need to adapt the color format to your Chart class
    }

    constexpr double default_frequency = 40.0;
    constexpr double default_amplitude = -6.0;

    double clamp(double value, double min, double max) {
        return std::clamp(value, min, max);
    }

    constexpr float lineWidth = 1.0f;
    const std::string& font = "12px roboto";
    const std::string& strokeStyle = "rgba(140,140,140,0.5)";
    const std::string& fillStyleText = "#aaa";
    const std::string& fillStyleAmplitude = "rgba(0,0,255,0.7)";
    const std::string& fillStyleFrequency = "rgba(0,255,0,0.7)";

    ChartJS::CustomPlugin::afterDatasetsDrawHandler CrosshairPlugin;

    CrosshairPlugin.id = "crossHairPlugin";
    CrosshairPlugin.afterDatasetsDraw = [](ChartJS::Chart& chart) -> void {
        if (chart.crosshair) {
            const auto& chartArea = chart.chartArea;
            const float minX = chartArea.left;
            const float maxX = chartArea.right;
            const float minY = chartArea.top;
            const float maxY = chartArea.bottom;

            auto& ctx = chart.ctx;
            float x = clamp(chart.crosshair.x, minX, maxX);
            float y = clamp(chart.crosshair.y, minY, maxY);

            const auto& leftX = chart.scales[0].left; // x-axis-frame
            const auto& rightX = chart.scales[0].right;
            const auto& topY = chart.scales[1].top; // y-axis-amplitude or y-axis-frequency
            const auto& bottomY = chart.scales[1].bottom;

            ctx.save();
            ctx.beginPath();

            // Draw new vertical line
            ctx.moveTo(x, topY);
            ctx.lineTo(x, bottomY);
            ctx.lineWidth = lineWidth;
            ctx.strokeStyle = strokeStyle;
            ctx.stroke();

            // Draw new horizontal line
            ctx.moveTo(leftX, y);
            ctx.lineTo(rightX, y);
            ctx.lineWidth = lineWidth;
            ctx.strokeStyle = strokeStyle;
            ctx.stroke();

            // Draw text for X and Y values at the axes
            const float xValue = chart.scales[0].getValueForPixel(x);
            const float yValue = chart.scales[chart.yAxisAmplitudeVisibleFlag ? 1 : 0].getValueForPixel(y);

            ctx.fillStyle = fillStyleText; // Text color
            ctx.font = font; // Text font and size

            // Text alignment and position adjustments as needed
            ctx.fillText(std::to_string(std::round(xValue)), x - 18, 64); // top-most x-axis
            ctx.fillText(std::to_string(std::round(xValue)), x - 18, bottomY + 18); // bottom-most x-axis

            if (chart.yAxisAmplitudeVisibleFlag) {
                ctx.fillText(std::to_string(yValue) + " dBFS", 19, y);
                // Draw a point at the amplitude intersection
                ctx.beginPath();
                ctx.arc(x, y, 5, 0, 2 * M_PI); // Draw a 5px radius point
                ctx.fillStyle = fillStyleAmplitude;
                ctx.fill();
            } else {
                ctx.fillText(std::to_string(yValue) + " Hz", rightX + 10, y);
                // Draw a point at the frequency intersection
                ctx.beginPath();
                ctx.arc(x, y, 5, 0, 2 * M_PI); // Draw a 5px radius point
                ctx.fillStyle = fillStyleFrequency;
                ctx.fill();
            }

            ctx.restore();
        }
    };

    ChartJS::registerPlugin(CrosshairPlugin); // Register the plugin

    // Assuming these constants are defined elsewhere
    extern const double g_default_amplitude;
    extern const double g_default_frequency;

    class OscInterval {
    public:
        long double amplitude;
        long double frequency;
        const long long int frame;
        const long long int time_step;

        OscInterval(const long double amplitude = g_default_amplitude,
                    const long double frequency = g_default_frequency,
                    const long long int frame = 0,
                    const long long  time_step = 0)
            : amplitude(amplitude), frequency(frequency), frame(frame), time_step(time_step) {}
    };

    class FORMANTS {
    public:
        std::string shape;
        bool amplitude_bezierCurve_flag;
        bool frequency_bezierCurve_flag;
        std::vector<OscInterval> intervals;

        FORMANTS(const std::string& shape = "Sine",
                 bool amplitude_bezierCurve_flag = false,
                 bool frequency_bezierCurve_flag = false)
            : shape(shape), amplitude_bezierCurve_flag(amplitude_bezierCurve_flag),
              frequency_bezierCurve_flag(frequency_bezierCurve_flag) {}

        void push(const OscInterval& interval) {
            intervals.push_back(interval);
        }
    };

    // Usage example
    std::vector<FORMANTS> Formants;
    Formants[0].push(OscInterval{.amplitude = -6.0, .frequency = 50.0, .frame = 0, .time_step = 0});
    Formants[0].push(OscInterval{.amplitude = -4.5, .frequency = 60.0, .frame = 200, .time_step = 15});
    Formants[0].push(OscInterval{.amplitude = -4.0, .frequency = 65.0, .frame = 265, .time_step = 30});
    Formants[0].push(OscInterval{.amplitude = -5.5, .frequency = 60.0, .frame = 600, .time_step = 45});
    Formants[0].push(OscInterval{.amplitude = -5.8, .frequency = 50.0, .frame = 880, .time_step = 60});
    Formants[0].push(OscInterval{.amplitude = -6.0, .frequency = 40.0, .frame = 1040, .time_step = 75});
    Formants[0].push(OscInterval{.amplitude = -7.0, .frequency = 30.0, .frame = 1300, .time_step = 90});
    Formants[0].push(OscInterval{.amplitude = -11.0, .frequency = 20.0, .frame = 2000, .time_step = 105});

    auto plotAmplitudes = [](const std::vector<OscInterval>& intervals) {
        std::vector<ChartJS::Point> points;
        for (const auto& interval : intervals) {
            points.emplace_back(ChartJS::Point<>{.x = interval.amplitude, .y = interval.frame});
        }
        return points;
    };

    auto plotFrequencies = [](const std::vector<OscInterval>& intervals) {
        std::vector<Point<>> points;
        for (const auto& interval : intervals) {
            points.emplace_back(ChartJS::Point<>{.x = interval.frequency, .y = interval.frame});
        }
        return points;
    };

    ChartJS::Chart MyChart; // std::map<std::string, ConfigValue> MyChart;

    // Add full config to MyChart
    MyChart.setConfig("type", ChartJS::ChartType<std::string>{"line"};

    ChartJS::Data<std::string> data = ChartJS::Data{ 
        .datasets = std::vector<ChartJS::Dataset<std::string>>{
            ChartJS::Dataset<std::string>{
                .label = "Amplitude (dBFS)",
                .data = plotAmplitudes(Formants[0]),
                .borderColor = "blue",
                .backgroundColor = ChartJS::RGB<uint32_t>{.red=0, .green=0, .blue=255},
                .yAxisID = "y-axis-amplitude",
                .xAxisID = "x-axis-frame" }, 
            ChartJS::Dataset<std::string>{
                .label = "Frequency (Hz)",
                .data = plotFrequencies(Formants[0]),
                .borderColor = "green",
                .backgroundColor = ChartJS::RGB<uint32_t>{.red=0, .green=255, .blue=0},
                .yAxisID = "y-axis-frequency",
                .xAxisID = "x-axis-frame" } } }; // ChartJS::Data
    
    MyChart.setConfig("data", data);

    ChartJS::Data<std::string> options = ChartJS::Options{ 
        .scales = ChartJS::Scales<>{ 
            ChartJS::YAxis<std::string>{
                .axisID = "y-axis-amplitude",
                .type = ChartJS::AxisType::linear,
                .title = ChartJS::AxisTitle<std::string>{
                    .text = "dBFS ( Decibels relative to Full Scale )", 
                    .display = true },
                .display = true,
                .position = ChartJS::YAxisPosition::left,
                .grid = ChartJS::AxisGrid{.drawOnChartArea = true},
                .ticks = ChartJS::AxisTicks{
                    .callback = [](
                        long long int const value, 
                        long long int const index, 
                        const std::vector<>& ticks) -> std::string {
                            // call the default formatter, forwarding `this`
                            return ChartJS::Ticks::formatters::numeric::apply(this, std::vector<>{value, index, ticks}) + " dBFS"; } } }, // ChartJS::YAxis
            ChartJS::YAxis<std::string>{
                .type = ChartJS::AxisType::linear,
                .title = ChartJS::AxisTitle<std::string>{
                    .axisID = "y-axis-frequency",
                    .text = "Hz",
                    .display = true },
                .display = true,
                .position = ChartJS::YAxisPosition::right,
                .grid = ChartJS::AxisGrid{.drawOnChartArea = false},
                .ticks = ChartJS::AxisTicks{
                    .callback = [](
                        long long int const value, 
                        long long int const index, 
                        const std::vector<>& ticks) -> std::string {
                            // call the default formatter, forwarding `this`
                            return ChartJS::Ticks::formatters::numeric::apply(this, std::vector<>{value, index, ticks}) + " Hz"; } } }, // ChartJS::YAxis
            ChartJS::XAxis<std::string>{
                .axisID = "x-axis-frame",
                .type = ChartJS::AxisType::linear,
                .title = ChartJS::AxisTitle<std::string>{
                    .axisID = "Audio Sample ( Frame ) ",
                    .display = true },
                .display = true,
                .position = ChartJS::XAxisPosition::bottom,
                .grid = ChartJS::AxisGrid{.drawOnChartArea = false},
                .ticks = ChartJS::AxisTicks{
                    .callback = [](
                        long long int const value, 
                        long long int const index, 
                        const std::vector<>& ticks) -> std::string {
                            // call the default formatter, forwarding `this`
                            return ChartJS::Ticks::formatters::numeric::apply(this, std::vector<>{value, index, ticks}) + " Hz"; } } }, // ChartJS::XAxis
            ChartJS::XAxis<std::string>{
                .axisID = "x-axis-frame-dupl",
                .type = ChartJS::AxisType::linear,
                .title = ChartJS::AxisTitle<std::string>{
                    .axisID = "Audio Sample ( Frame ) ",
                    .display = true },
                .display = true,
                .position = ChartJS::XAxisPosition::top,
                .grid = ChartJS::AxisGrid{.drawOnChartArea = false},
                .ticks = ChartJS::AxisTicks{
                    .callback = [](
                        long long int const value, 
                        long long int const index, 
                        const std::vector<>& ticks) -> std::string {
                            // call the default formatter, forwarding `this`
                            return ChartJS::Ticks::formatters::numeric::apply(this, std::vector<>{value, index, ticks}); } } } }, // ChartJS::Scales
        .plugins = ChartJS::Plugins{ 
            .legend = ChartJS::Legend{ 
                .labels = ChartJS::LegendLabels{ 
                    .fontColor = ChartJS::RGBA{.red=0, .green=0, .blue=0, .alpha=0.5}, 
                    .fontSize = 12, 
                    .boxWidth = 12, 
                    .padding = 12, 
                    .usePointStyle = true, 
                    .useLineStyle = true, 
                    .useColor = true, 
                    .display = true, 
                    .position = ChartJS::LegendPosition::top }, // ChartJS::Legend
                .display = true, 
                .position = ChartJS::LegendPosition::top }, // ChartJS::Legend
            .crosshair = ChartJS::Crosshair{ 
                .enabled = true, 
                .line = ChartJS::CrosshairLine{ 
                    .color = ChartJS::RGBA{.red=0, .green=0, .blue=0, .alpha=0.5}, 
                    .width = 1, 
                    .dashPattern = std::vector<>{5, 5} } } }, // ChartJS::Plugins
            .tooltip = ChartJS::Tooltip{
                // Enable custom tooltips
                .enabled = true,
                .mode = ChartJS::Options::Plugins::Tooltip::mode::index,
                .position = ChartJS::TooltipPosition::nearest,
                .bodyFontSize = 12, // Tooltip font size
                .callbacks = ChartJS::TooltipCallbacks{
                    .title = [](tooltips, data) {
                        // Assuming the first dataset is for amplitude and has complete frame and time_step data
                        //const tt = tooltips[0];
                        const tt2 = tooltips[1];
                        //const tmpTimeStep = tt.label;
                        const tmpFrame = tt2.label;
                        /*
                        const tmpAmplitude = tt.formattedValue;
                        const tmpfrequency = tt2.formattedValue;
                        */
                        return `Frame: ${tmpFrame}`; },
                    .label = [](tooltipItem, data) {
                        // tooltipItem is an object containing properties of the tooltip
                        // data is an object containing all data passed to the chart
                        std::string yLabel = tooltipItem.formattedValue;
                        const std::string xLabel = tooltipItem.dataset.label;
                        if (xLabel.match(/^Amplitude/)) {
                            yLabel = std::format("Amplitude: {} dBFS", yLabel); } 
                        else if (xLabel.match(/^Frequency/)) {
                            yLabel = std::format("Frequency: {} Hz", yLabel); }
                        return yLabel; } } } }; // ChartJS::Options

    MyChart.setConfig("options", options);

    MyChart.addEventListener(ChartJS::AddEventListener{
        .windowEvent = ChartJS::windowEvent::mousemove, 
        .m_hWnd = nullptr, 
        .callback = updateCrossHair});

    MyChart.addEventListener(ChartJS::AddEventListener{
        .windowEvent = ChartJS::windowEvent::click, 
        .m_hWnd = nullptr, 
        .callback = [](ChartJS::Event const event) {
        // ... handle mouse move event
    }});

    MyChart.yAxisAmplitudeVisibleFlag = true; // Set the custom flag to show amplitude on the y-axis

} // namespace TTSCurveEditorNamespace


