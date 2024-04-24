import numpy as np
import cv2


cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()

    cv2.imshow('video stream', frame)
    if cv2.waitKey(1) == ord('q') or cv2.waitKey(1) == ord('Q'):
        break

cap.release()
cv2.destroyAllWindows()