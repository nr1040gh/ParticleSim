import matplotlib.pyplot as plt
import matplotlib.patches as patches
import csv
import os
import cv2
from PIL import Image
import io
import numpy as np


#https://stackoverflow.com/questions/57316491/how-to-convert-matplotlib-figure-to-pil-image-object-without-saving-image
def fig2img(fig):
    """Convert a Matplotlib figure to a PIL Image and return it"""
    
    buf = io.BytesIO()
    fig.savefig(buf)
    buf.seek(0)
    img = Image.open(buf)
    return img



sim_file = os.path.join(os.pardir, 'results','results.csv')
outvid = os.path.join(os.pardir, 'videos','simulation.avi')

fig, ax = plt.subplots()
ax.set_box_aspect(1)

gif = []
images = []

with open(sim_file, 'r') as read_obj:
    reader = csv.reader(read_obj)

    frame_count = 0
    for row in reader:
        if frame_count == 0:
            boxleft = int(row[0])
            boxright = int(row[1])
            boxtop = int(row[2])
            boxbot = int(row[3])
            fps = float(row[4])

            
        else:
            x = float(row[0])
            y = float(row[1])
            radius = float(row[2])

            rect = patches.Rectangle((0, 0), boxright, boxtop, linewidth=1, edgecolor='b', facecolor='w')
            circle1 = plt.Circle((x, y), radius, color='r', clip_on=False)
            
            ax.add_patch(rect)
            ax.add_patch(circle1)

            ax.set_xlim(boxleft, boxright)
            ax.set_ylim(boxbot, boxtop)
            
            img = fig2img(fig)

            if frame_count == 1:
                fourcc = cv2.VideoWriter_fourcc(*'DIVX')    
                video = cv2.VideoWriter(outvid,fourcc, fps, img.size)
            


            video.write(cv2.cvtColor(np.array(img), cv2.COLOR_RGB2BGR))
            images.append(img)

            ax.cla()


        frame_count += 1
        
video.release()
        
