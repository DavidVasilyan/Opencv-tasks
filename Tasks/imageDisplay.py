import cv2

src = cv2.imread(("lena.jpg"), 1)

while True:
    cv2.imshow("Window", src)
    c = cv2.waitKey(0)
    if c == ord('q') or ord('Q'):
        break