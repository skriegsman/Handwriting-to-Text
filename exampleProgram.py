import cv2
import numpy as np
from matplotlib import pyplot

img = cv2.imread('pictures/abcdef.jpg',0)
img2 = img.copy()
template = cv2.imread('template.jpg',0)
w, h = template.shape[::-1]
# All the 6 methods for comparison in a list
methods = ['cv2.TM_CCOEFF', 'cv2.TM_CCOEFF_NORMED', 'cv2.TM_CCORR',
            'cv2.TM_CCORR_NORMED', 'cv2.TM_SQDIFF', 'cv2.TM_SQDIFF_NORMED']
for meth in methods:
    img = img2.copy()
    method = eval(meth)
    # Apply template Matching
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
