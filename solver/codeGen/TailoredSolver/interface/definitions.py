import numpy
import ctypes

name = "TailoredSolver"
requires_callback = True
lib = "lib/libTailoredSolver.so"
lib_static = "lib/libTailoredSolver.a"
c_header = "include/TailoredSolver.h"
nstages = 40

# Parameter             | Type    | Scalar type      | Ctypes type    | Numpy type   | Shape     | Len
params = \
[("lb"                  , "dense" , ""               , ctypes.c_double, numpy.float64, (360,   1),  360),
 ("ub"                  , "dense" , ""               , ctypes.c_double, numpy.float64, (360,   1),  360),
 ("hu"                  , "dense" , ""               , ctypes.c_double, numpy.float64, ( 80,   1),   80),
 ("xinit"               , "dense" , ""               , ctypes.c_double, numpy.float64, (  7,   1),    7),
 ("x0"                  , "dense" , ""               , ctypes.c_double, numpy.float64, (360,   1),  360),
 ("all_parameters"      , "dense" , ""               , ctypes.c_double, numpy.float64, (1080,   1), 1080)]

# Output                | Type    | Scalar type      | Ctypes type    | Numpy type   | Shape     | Len
outputs = \
[("U"                   , ""      , ""               , ctypes.c_double, numpy.float64,     (  4,),  160),
 ("X"                   , ""      , ""               , ctypes.c_double, numpy.float64,     (  5,),  200)]

# Info Struct Fields
info = \
[('it', ctypes.c_int),
 ('it2opt', ctypes.c_int),
 ('res_eq', ctypes.c_double),
 ('res_ineq', ctypes.c_double),
 ('rsnorm', ctypes.c_double),
 ('rcompnorm', ctypes.c_double),
 ('pobj', ctypes.c_double),
 ('dobj', ctypes.c_double),
 ('dgap', ctypes.c_double),
 ('rdgap', ctypes.c_double),
 ('mu', ctypes.c_double),
 ('mu_aff', ctypes.c_double),
 ('sigma', ctypes.c_double),
 ('lsit_aff', ctypes.c_int),
 ('lsit_cc', ctypes.c_int),
 ('step_aff', ctypes.c_double),
 ('step_cc', ctypes.c_double),
 ('solvetime', ctypes.c_double),
 ('fevalstime', ctypes.c_double),
 ('solver_id', ctypes.c_int * 8)
]

# Dynamics dimensions
#   nvar    |   neq   |   dimh    |   dimp    |   diml    |   dimu    |   dimhl   |   dimhu    
dynamics_dims = [
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2), 
	(9, 7, 2, 27, 9, 9, 0, 2)
]