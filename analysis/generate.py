import matplotlib.pyplot as plt
import matplotlib.patches as patches
import csv
import os
from PIL import Image, ImageDraw


sim_file = os.path.join(os.pardir, 'results','results.csv')
outfolder = os.path.join(os.pardir, 'images')
outgif = os.path.join(os.pardir, 'gifs','simulation.gif')


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

            width = boxright-boxleft
            height = boxright-boxleft

            

        else:
            x = float(row[0])
            y = float(row[1])
            radius = float(row[2])


            img = Image.new("RGB", (width+10,height+10))

            box = ImageDraw.Draw(img)
            box.rectangle([(boxleft,boxbot),(boxright,boxtop)],outline='blue')

            shape1 = [(x, y), (radius, radius)]
            p1 = ImageDraw.Draw(img)
            p1.ellipse(shape1,fill='red',outline='black')

            images.append(img)


        frame_count += 1

images[0].save(outgif,
               save_all = True, append_images = images[1:], 
               optimize = False, duration = 15)