import cv2
import numpy as np
from matplotlib import pyplot



""" ---Initial Processing of given Image--- """
#load image in greyscale (0) under var name img
originalImage = cv2.imread('pictures/abcdef.png')
workingImage = cv2.cvtColor(originalImage.copy(), cv2.COLOR_BGR2GRAY)
#add adaptive thresholding  with a gaussian blur here to get rid of grays and make the page black and white only
#guassian blur smooths immage and gets rid of misc noise in the image
workingImage = cv2.adaptiveThreshold(workingImage, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 5, 1)



template = cv2.imread('template.jpg',0)
w, h = template.shape[::-1]
# All the 6 methods for comparison in a list
methods = ['cv2.TM_CCOEFF', 'cv2.TM_CCOEFF_NORMED', 'cv2.TM_CCORR',
            'cv2.TM_CCORR_NORMED', 'cv2.TM_SQDIFF', 'cv2.TM_SQDIFF_NORMED']
for meth in methods:
    method = eval(meth)
    res = cv2.matchTemplate(img,template,method)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)
    # If the method is TM_SQDIFF or TM_SQDIFF_NORMED, take minimum
    if method in [cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]:
        top_left = min_loc
    else:
        top_left = max_loc
    bottom_right = (top_left[0] + w, top_left[1] + h)
    cv2.rectangle(img,top_left, bottom_right, 255, 2)
    pyplot.subplot(121),pyplot.imshow(res,cmap = 'gray')
    pyplot.title('Matching Result'), pyplot.xticks([]), pyplot.yticks([])
    pyplot.subplot(122),pyplot.imshow(img,cmap = 'gray')
    pyplot.title('Detected Point'), pyplot.xticks([]), pyplot.yticks([])
    pyplot.suptitle(meth)
    pyplot.show()

""" -----------------------FINDS CONTOURS (NOT IN USE)-----------------------------------
#Takes the white filtered frame and detects contours, then draws them over the line detection from above
#contours, hierarchy = cv2.findContours(image, .....)
#CHAIN_APPROX_SIMPLE simplifies the contours by removing uneeded points making it more memory efficient than CHAIN_APPROX_NONE
contours, ret = cv2.findContours(workingImage, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
for contour in contours: #For each contour
    [x, y, X, Y] = cv2.boundingRect(contour) # get rectangle bounding contour
    cv2.rectangle(originalImage, (x, y), (x + X, y + Y), (255, 0, 255), 1) # draw pink rectangle around contour on original image
"""
#Displays the image seen by the computer for analysis
cv2.imshow("Original Image", originalImage)
cv2.waitKey(0)
cv2.destroyAllWindows()
