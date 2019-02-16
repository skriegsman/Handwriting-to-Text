import cv2
import pytesseract
import matplotlib.pyplot as plt
import numpy as np

""" ---Initial Image Processing--- """
image = cv2.imread("pictures/skew1.png", 0)
ret, thresh = cv2.threshold(image,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
invert = cv2.bitwise_not(thresh)

""" ---Blurs the image to remove noise and smooth edges--- """
blur = cv2.GaussianBlur(invert, (3,3), 0.1)

""" ---Auto Rotates the Image to Correct Skew--- """
coords = np.column_stack(np.where(blur > 0))
angle = cv2.minAreaRect(coords)[-1]

if angle < -45: angle = -(90 + angle)
else: angle = -angle

(h, w) = image.shape[:2]
center = (w // 2, h // 2)
M = cv2.getRotationMatrix2D(center, angle, 1.0)
rotated = cv2.warpAffine(invert, M, (w, h), flags=cv2.INTER_CUBIC, borderMode=cv2.BORDER_REPLICATE)


""" ---Auto Crop Image using the above minAreaRect--- """
points = np.argwhere(rotated==255)
points = np.fliplr(points)
x, y, w, h = cv2.boundingRect(points)
x, y, w, h = x-10, y-10, w+20, h+20
crop = rotated[y:y+h, x:x+w]

""" ---Finds the text in the processed image--- """
text = pytesseract.image_to_string(rotated, config= '--psm 1 --oem 1')
print(text)


cv2.imshow("image", image)
cv2.imshow("rotate", rotated)
cv2.imshow("crop", crop)
cv2.waitKey(0)
cv2.destroyAllWindows()
