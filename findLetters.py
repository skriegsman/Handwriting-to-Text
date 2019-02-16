import cv2
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
originalImage = cv2.imread('pictures/abcdef.png')
workingImage = cv2.cvtColor(originalImage.copy(), cv2.COLOR_BGR2GRAY)
#add adaptive thresholding  with a gaussian blur here to get rid of grays and make the page black and white only
#guassian blur smooths immage and gets rid of misc noise in the image
workingImage = cv2.adaptiveThreshold(workingImage, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 5, 1)


""" ---This section displays the image--- """ #For Testing only (not in final product)
cv2.imshow("Original Image", originalImage)
cv2.waitKey(0)
cv2.destroyAllWindows()
