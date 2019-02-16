import cv2
import pytesseract
import numpy as np

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


""" ---This section gets the image ready to be analysed--- """
#load image in greyscale (0) under var name img
originalImage = cv2.imread('pictures/harrypotter.png')
workingImage = cv2.cvtColor(originalImage.copy(), cv2.COLOR_BGR2GRAY)

kernel = np.ones((1, 1), np.uint8)
workingImage = cv2.erode(workingImage, kernel, iterations=1)
workingImage = cv2.dilate(workingImage, kernel, iterations=1)

workingImage = cv2.threshold(workingImage, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)[1]


""" ---Finds text in the image using tesseract--- """
text = pytesseract.image_to_string(workingImage, lang="eng")

print(text)
