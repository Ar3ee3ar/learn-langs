# import ctypes
# import os
# from pathlib import Path
# # print(os.environ["PATH"])
# # either
# # libc = ctypes.CDLL("D:/personal_proj/ml-basic/c++/mnist_ml/lib/libdata.so")
# # dll_path = Path(r"D:/personal_proj/ml-basic/cpp/mnist_ml/lib/libdata.dll")
# # print(dll_path.exists())   # should print True
# # ctypes.WinDLL(str(dll_path))
# # print("Loaded OK")

# if __name__ == "__main__":
#     # Load the shared library into ctypes
#     libname = Path(r"D:/personal_proj/ml-basic/cpp/mnist_ml/lib/libdata.dll")
#     c_lib = ctypes.CDLL(libname)
#     dh = c_lib.data_handler()
#     dh.read_feature_vector("D:/personal_proj/ml-basic/cpp/mnist_ml/train-images.idx3-ubyte")
#     dh.read_feature_labels("D:/personal_proj/ml-basic/cpp/mnist_ml/train-labels.idx1-ubyte")
#     dh.split_data()
#     dh.count_classes()

import sys
sys.path.append("D:/personal_proj/ml-basic/cpp/mnist_ml/python")
import libdata

dh = libdata.DataHandler()
dh.read_feature_vector("../../cpp/mnist_ml/train-images.idx3-ubyte")

