from PIL import Image
import sys
import time
def printf(format, *args):
    sys.stdout.write(format % args)
image = Image.open("blahaj.jpeg")
basewidth = 100
wpercent = (basewidth/float(image.size[0]))
hsize = int((float(image.size[1])*float(wpercent)))
image = image.resize((basewidth,hsize), Image.ANTIALIAS)
image = image.convert('1', dither=1)
image.save('dit.gif')
width, height = image.size
for y in range(height):
    for x in range(width):
        l = image.getpixel((x,y))
        if l == 0:
            print("1")
#            time.sleep(0.01)
        else:
            print("0")
#            time.sleep(0.01)
        #if x != width-1:
        #    print(end=",")
        #print(f"x = {x}, y = {y}, {l}")
    print("2")
print("3")
