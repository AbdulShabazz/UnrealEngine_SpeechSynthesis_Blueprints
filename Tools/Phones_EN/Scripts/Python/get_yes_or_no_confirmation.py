

def get_yes_or_no_confirmation(prompt: str) -> str:
    '''Prompts the user for a yes or no response. Returns 'y' or 'n'. '''
    response_str = {"yes": "y", "y": "y", "no": "n", "n": "n"}
    valid_responses = {"yes": True, "y": True, "no": False, "n": False}

    response = input(prompt).lower()

    while True:
        if response in valid_responses:
            return response_str[response]
        else:
            print("Invalid response. Please enter 'yes' or 'no'.")
