import ctypes
import numpy as np
from PIL import Image

lib = ctypes.CDLL('./libraycasting.so')

class Vec3(ctypes.Structure):
    _fields_ = [("x", ctypes.c_double),
                ("y", ctypes.c_double),
                ("z", ctypes.c_double)]

class Sphere(ctypes.Structure):
    _fields_ = [("center", Vec3),
                ("radius", ctypes.c_double)]

lib.generate_ray_casting.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.POINTER(Sphere), ctypes.POINTER(ctypes.c_int)]

def generate_image(width, height, sphere):
    output = np.zeros((height, width), dtype=np.int32)
    output_ptr = output.ctypes.data_as(ctypes.POINTER(ctypes.c_int))

    lib.generate_ray_casting(width, height, ctypes.byref(sphere), output_ptr)

    return output

if __name__ == "__main__":
    width, height = 800, 600
    sphere = Sphere(center=Vec3(x=0, y=0, z=-5), radius=1)
    image_data = generate_image(width, height, sphere)
    
    # Cria a imagem usando a biblioteca PIL
    image = Image.fromarray(image_data.astype(np.uint8))
    image.show()
