import cv2 as cv
import numpy as np

img = cv.imread(("lena.jpg"), 1)

if img is None:
    print("ERROR")
    exit

points = (200, 200)
resize = cv.resize(img,  points)

cv.imshow("RESIZE", resize)

Flip = cv.flip(img, 1)
Flip = cv.flip(Flip, 0)
cv.imshow("FLIP", Flip)

crop = img[150:300, 200:330]
cv.imshow("CROP", crop)

height, width = img.shape[:2]
rotation_matrix = cv.getRotationMatrix2D((width / 2, height / 2), -45, 1)
rotateIMG = cv.warpAffine(img, rotation_matrix, (width, height))
cv.imshow("ROTATE", rotateIMG)

cv.imwrite("crop.jpg", crop)
cv.imwrite("resize.jpg", resize)
cv.imwrite("flip.jpg", Flip)
cv.imwrite("rotate.jpg", rotateIMG)

c = cv.waitKey(0)
cv.destroyAllWindows()