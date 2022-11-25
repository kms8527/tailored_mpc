/*
TailoredSolver : A fast customized optimization solver.

Copyright (C) 2013-2022 EMBOTECH AG [info@embotech.com]. All rights reserved.


This program is distributed in the hope that it will be useful.
EMBOTECH makes NO WARRANTIES with respect to the use of the software 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
PARTICULAR PURPOSE. 

EMBOTECH shall not have any liability for any damage arising from the use
of the software.

This Agreement shall exclusively be governed by and interpreted in 
accordance with the laws of Switzerland, excluding its principles
of conflict of laws. The Courts of Zurich-City shall have exclusive 
jurisdiction in case of any dispute.

*/

/* Generated by FORCESPRO v6.0.0 on Thursday, November 24, 2022 at 4:08:46 PM */
#ifndef TailoredSolver_H
#define TailoredSolver_H

#ifndef SOLVER_STDIO_H
#define SOLVER_STDIO_H
#include <stdio.h>
#endif
#ifndef SOLVER_STRING_H
#define SOLVER_STRING_H
#include <string.h>
#endif


#ifndef SOLVER_STANDARD_TYPES
#define SOLVER_STANDARD_TYPES

typedef signed char solver_int8_signed;
typedef unsigned char solver_int8_unsigned;
typedef char solver_int8_default;
typedef signed short int solver_int16_signed;
typedef unsigned short int solver_int16_unsigned;
typedef short int solver_int16_default;
typedef signed int solver_int32_signed;
typedef unsigned int solver_int32_unsigned;
typedef int solver_int32_default;
typedef signed long long int solver_int64_signed;
typedef unsigned long long int solver_int64_unsigned;
typedef long long int solver_int64_default;

#endif


/* DATA TYPE ------------------------------------------------------------*/
typedef double TailoredSolver_float;
typedef double TailoredSolver_ldl_s_float;
typedef double TailoredSolver_ldl_r_float;
typedef double TailoredSolver_callback_float;

typedef double TailoredSolverinterface_float;

/* SOLVER SETTINGS ------------------------------------------------------*/

/* MISRA-C compliance */
#ifndef MISRA_C_TailoredSolver
#define MISRA_C_TailoredSolver (0)
#endif

/* restrict code */
#ifndef RESTRICT_CODE_TailoredSolver
#define RESTRICT_CODE_TailoredSolver (0)
#endif

/* print level */
#ifndef SET_PRINTLEVEL_TailoredSolver
#define SET_PRINTLEVEL_TailoredSolver    (0)
#endif

/* timing */
#ifndef SET_TIMING_TailoredSolver
#define SET_TIMING_TailoredSolver    (1)
#endif

/* Numeric Warnings */
/* #define PRINTNUMERICALWARNINGS */

/* maximum number of iterations  */
#define SET_MAXIT_TailoredSolver			(150)	

/* scaling factor of line search (FTB rule) */
#define SET_FLS_SCALE_TailoredSolver		(TailoredSolver_float)(0.99)      

/* maximum number of supported elements in the filter */
#define MAX_FILTER_SIZE_TailoredSolver	(150) 

/* maximum number of supported elements in the filter */
#define MAX_SOC_IT_TailoredSolver			(4) 

/* desired relative duality gap */
#define SET_ACC_RDGAP_TailoredSolver		(TailoredSolver_float)(0.0001)

/* desired maximum residual on equality constraints */
#define SET_ACC_RESEQ_TailoredSolver		(TailoredSolver_float)(1E-06)

/* desired maximum residual on inequality constraints */
#define SET_ACC_RESINEQ_TailoredSolver	(TailoredSolver_float)(1E-06)

/* desired maximum violation of complementarity */
#define SET_ACC_KKTCOMPL_TailoredSolver	(TailoredSolver_float)(1E-06)


/* SOLVER RETURN CODES----------------------------------------------------------*/
/* solver has converged within desired accuracy */
#define OPTIMAL_TailoredSolver      (1)

/* maximum number of iterations has been reached */
#define MAXITREACHED_TailoredSolver (0)

/* solver has stopped due to a timeout */
#define TIMEOUT_TailoredSolver   (2)

/* solver stopped externally */
#define EXIT_EXTERNAL_TailoredSolver (3)

/* wrong number of inequalities error */
#define INVALID_NUM_INEQ_ERROR_TailoredSolver  (-4)

/* factorization error */
#define FACTORIZATION_ERROR_TailoredSolver   (-5)

/* NaN encountered in function evaluations */
#define BADFUNCEVAL_TailoredSolver  (-6)

/* no progress in method possible */
#define NOPROGRESS_TailoredSolver   (-7)

/* regularization error */
#define REGULARIZATION_ERROR_TailoredSolver   (-9)

/* invalid values in parameters */
#define PARAM_VALUE_ERROR_TailoredSolver   (-11)

/* too small timeout given */
#define INVALID_TIMEOUT_TailoredSolver   (-12)

/* thread error */
#define THREAD_FAILURE_TailoredSolver  (-98)

/* locking mechanism error */
#define LOCK_FAILURE_TailoredSolver  (-99)

/* licensing error - solver not valid on this machine */
#define LICENSE_ERROR_TailoredSolver  (-100)

/* Insufficient number of internal memory instances.
 * Increase codeoptions.max_num_mem. */
#define MEMORY_INVALID_TailoredSolver (-101)
/* Number of threads larger than specified.
 * Increase codeoptions.nlp.max_num_threads. */
#define NUMTHREADS_INVALID_TailoredSolver (-102)

/* INTEGRATORS RETURN CODE ------------*/
/* Integrator ran successfully */
#define INTEGRATOR_SUCCESS (11)
/* Number of steps set by user exceeds maximum number of steps allowed */
#define INTEGRATOR_MAXSTEPS_EXCEEDED (12)


/* MEMORY STRUCT --------------------------------------------------------*/
typedef struct TailoredSolver_mem TailoredSolver_mem;
#ifdef __cplusplus
extern "C" {
#endif
/* MEMORY STRUCT --------------------------------------------------------*/
extern TailoredSolver_mem * TailoredSolver_external_mem(void * mem_ptr, solver_int32_unsigned i_mem, size_t mem_size);
extern size_t TailoredSolver_get_mem_size( void );
extern size_t TailoredSolver_get_const_size( void );
#ifdef __cplusplus
}
#endif

/* PARAMETERS -----------------------------------------------------------*/
/* fill this with data before calling the solver! */
typedef struct
{
    /* vector of size 480 */
    TailoredSolver_float lb[480];

    /* vector of size 400 */
    TailoredSolver_float ub[400];

    /* vector of size 200 */
    TailoredSolver_float hu[200];

    /* vector of size 10 */
    TailoredSolver_float xinit[10];

    /* vector of size 480 */
    TailoredSolver_float x0[480];

    /* vector of size 1240 */
    TailoredSolver_float all_parameters[1240];

    /* scalar */
    solver_int32_unsigned num_of_threads;


} TailoredSolver_params;


/* OUTPUTS --------------------------------------------------------------*/
/* the desired variables are put here by the solver */
typedef struct
{
    /* vector of size 280 */
    TailoredSolver_float U[280];

    /* vector of size 200 */
    TailoredSolver_float X[200];


} TailoredSolver_output;


/* SOLVER INFO ----------------------------------------------------------*/
/* diagnostic data from last interior point step */
typedef struct
{
    /* iteration number */
    solver_int32_default it;

	/* number of iterations needed to optimality (branch-and-bound) */
	solver_int32_default it2opt;
	
    /* inf-norm of equality constraint residuals */
    TailoredSolver_float res_eq;
	
    /* inf-norm of inequality constraint residuals */
    TailoredSolver_float res_ineq;

	/* norm of stationarity condition */
    TailoredSolver_float rsnorm;

	/* max of all complementarity violations */
    TailoredSolver_float rcompnorm;

    /* primal objective */
    TailoredSolver_float pobj;	
	
    /* dual objective */
    TailoredSolver_float dobj;	

    /* duality gap := pobj - dobj */
    TailoredSolver_float dgap;		
	
    /* relative duality gap := |dgap / pobj | */
    TailoredSolver_float rdgap;		

    /* duality measure */
    TailoredSolver_float mu;

	/* duality measure (after affine step) */
    TailoredSolver_float mu_aff;
	
    /* centering parameter */
    TailoredSolver_float sigma;
	
    /* number of backtracking line search steps (affine direction) */
    solver_int32_default lsit_aff;
    
    /* number of backtracking line search steps (combined direction) */
    solver_int32_default lsit_cc;
    
    /* step size (affine direction) */
    TailoredSolver_float step_aff;
    
    /* step size (combined direction) */
    TailoredSolver_float step_cc;    

	/* solvertime */
	TailoredSolver_float solvetime;   

	/* time spent in function evaluations */
	TailoredSolver_float fevalstime;  

    /* solver ID of FORCESPRO solver */
    solver_int32_default solver_id[8];  


} TailoredSolver_info;









/* SOLVER FUNCTION DEFINITION -------------------------------------------*/
/* Time of Solver Generation: (UTC) Thursday, November 24, 2022 4:08:52 PM */
/* User License expires on: (UTC) Monday, September 25, 2023 10:00:00 PM (approx.) (at the time of code generation) */
/* Solver Static License expires on: (UTC) Monday, September 25, 2023 10:00:00 PM (approx.) */
/* Solver Id: fc8c44ee-d2e9-40f3-b0df-030c2036e216 */
/* examine exitflag before using the result! */
#ifdef __cplusplus
extern "C" {
#endif		

typedef solver_int32_default (*TailoredSolver_extfunc)(TailoredSolver_float* x, TailoredSolver_float* y, TailoredSolver_float* lambda, TailoredSolver_float* params, TailoredSolver_float* pobj, TailoredSolver_float* g, TailoredSolver_float* c, TailoredSolver_float* Jeq, TailoredSolver_float* h, TailoredSolver_float* Jineq, TailoredSolver_float* H, solver_int32_default stage, solver_int32_default iterations, solver_int32_default threadID);

extern solver_int32_default TailoredSolver_solve(TailoredSolver_params *params, TailoredSolver_output *output, TailoredSolver_info *info, TailoredSolver_mem *mem, FILE *fs, TailoredSolver_extfunc evalextfunctions_TailoredSolver);













#ifdef __cplusplus
}
#endif

#endif
