"""
This file will take in a picture of text and use cv2.matchTemplate to match
characters in the text to a letter. It will return a final string to be sent
to the printer.

Input: Picture of text
Output: String

Process:
- search for every template in the given textself.
- The top left most template match is the first char. The next leftmost one of the same y value is the second, etc
- Add chars to a string as they are found
"""
