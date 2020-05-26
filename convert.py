from PIL import Image
image = Image.open("syth.jpg")
basewidth = 1920
wpercent = (basewidth/float(image.size[0]))
hsize = int((float(image.size[1])*float(wpercent)))
image = image.resize((basewidth,hsize), Image.ANTIALIAS)
image = image.convert('1', dither=1)
image.save('dit.gif')
width, height = image.size
for y in range(height):
    print(end="{")
    for x in range(width):
        l = image.getpixel((x,y))
        if l == 0:
            print(end="1")
        else:
            print(end="0")
        if x != width-1:
            print(end=",")
        #print(f"x = {x}, y = {y}, {l}")
    print("} ,")
