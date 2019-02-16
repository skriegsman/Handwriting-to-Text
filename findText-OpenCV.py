import cv2
import pytesseract
import matplotlib.pyplot as plt
import numpy as np

image = cv2.imread("pictures/IMG_1781.jpg", 0)
ret, thresh = cv2.threshold(image,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
invert = cv2.bitwise_not(thresh)

#auto crop here

#auto blur

"""
coords = np.column_stack(np.where(crop > 0))
angle = cv2.minAreaRect(coords)[-1]
"""

#text = pytesseract.image_to_string(crop, config= '--psm 1 --oem 1')
#print(text)

cv2.imshow("show", invert)
cv2.waitKey(0)
cv2.destroyAllWindows()
