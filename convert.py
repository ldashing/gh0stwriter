from PIL import Image
import sys
import time
def printf(format, *args):
    sys.stdout.write(format % args)
image = Image.open("never.jpg")
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
            print(end="▅")
#            time.sleep(0.01)
        else:
            print(end="   ")
#            time.sleep(0.01)
        #if x != width-1:
         #   print("")
    print("")
    #print("2")
#print("3")
