import cv2
import numpy as np

#load image in greyscale (0) under var name img
originalImage = cv2.imread('pictures/abcdef.png')
workingImage = cv2.cvtColor(originalImage.copy(), cv2.COLOR_BGR2GRAY)

#add adaptive thresholding  with a gaussian blur here to get rid of grays and make the page black and white only
#guassian blur smooths immage and gets rid of misc noise in the image
workingImage = cv2.adaptiveThreshold(workingImage, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 5, 1)

#Takes the white filtered frame and detects contours, then draws them over the line detection from above
#contours, hierarchy = cv2.findContours(image, .....)
#CHAIN_APPROX_SIMPLE simplifies the contours by removing uneeded points making it more memory efficient than CHAIN_APPROX_NONE
contours, ret = cv2.findContours(workingImage, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
for contour in contours: #For each contour
    [x, y, X, Y] = cv2.boundingRect(contour) # get rectangle bounding contour
    cv2.rectangle(originalImage, (x, y), (x + X, y + Y), (255, 0, 255), 1) # draw pink rectangle around contour on original image

#Displays the image seen by the computer for analysis
cv2.imshow("Original Image", originalImage)
cv2.waitKey(0)
cv2.destroyAllWindows()
