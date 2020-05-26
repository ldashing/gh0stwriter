from PIL import Image
image = Image.open("cat2.jpg")
basewidth = 32
wpercent = (basewidth/float(image.size[0]))
hsize = int((float(image.size[1])*float(wpercent)))
image = image.resize((basewidth,hsize), Image.ANTIALIAS)
image = image.convert('1', dither=1)
image.save('dit.gif')
width, height = image.size
for y in range(height):
    line='0'
    print(end="{")
    for x in range(width):
        l = image.getpixel((x,y))
        if l == 0:
            print(end="1")
            line+='1'
        else:
            print(end="0")
            line+='0'
        if x != width-1:
            print(end=",")

    print(end="} ,")
    print(int(line,2))
