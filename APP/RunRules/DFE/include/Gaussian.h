/**\file */
#ifndef SLIC_DECLARATIONS_Gaussian_H
#define SLIC_DECLARATIONS_Gaussian_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define Gaussian_MersenneTwister_n (624)
#define Gaussian_MersenneTwister_seedOffset (8256754)
#define Gaussian_GaussianKernelGauss_mt (1)
#define Gaussian_GaussianKernelGauss1_mt (1)


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/




/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] ticks_GaussianKernel The number of ticks for which kernel "GaussianKernel" will run.
 * \param [out] outstream_mt Stream "mt".
 * \param [in] outstream_size_mt The size of the stream outstream_mt in bytes.
 * \param [out] outstream_mt1 Stream "mt1".
 * \param [in] outstream_size_mt1 The size of the stream outstream_mt1 in bytes.
 * \param [in] inmem_GaussianKernel_GaussianKernelGauss1_mt_seeds0 Mapped ROM inmem_GaussianKernel_GaussianKernelGauss1_mt_seeds0, should be of size (624 * sizeof(uint64_t)).
 * \param [in] inmem_GaussianKernel_GaussianKernelGauss_mt_seeds0 Mapped ROM inmem_GaussianKernel_GaussianKernelGauss_mt_seeds0, should be of size (624 * sizeof(uint64_t)).
 */
void Gaussian(
	uint64_t ticks_GaussianKernel,
	void *outstream_mt,
	size_t outstream_size_mt,
	void *outstream_mt1,
	size_t outstream_size_mt1,
	const uint64_t *inmem_GaussianKernel_GaussianKernelGauss1_mt_seeds0,
	const uint64_t *inmem_GaussianKernel_GaussianKernelGauss_mt_seeds0);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] ticks_GaussianKernel The number of ticks for which kernel "GaussianKernel" will run.
 * \param [out] outstream_mt Stream "mt".
 * \param [in] outstream_size_mt The size of the stream outstream_mt in bytes.
 * \param [out] outstream_mt1 Stream "mt1".
 * \param [in] outstream_size_mt1 The size of the stream outstream_mt1 in bytes.
 * \param [in] inmem_GaussianKernel_GaussianKernelGauss1_mt_seeds0 Mapped ROM inmem_GaussianKernel_GaussianKernelGauss1_mt_seeds0, should be of size (624 * sizeof(uint64_t)).
 * \param [in] inmem_GaussianKernel_GaussianKernelGauss_mt_seeds0 Mapped ROM inmem_GaussianKernel_GaussianKernelGauss_mt_seeds0, should be of size (624 * sizeof(uint64_t)).
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *Gaussian_nonblock(
	uint64_t ticks_GaussianKernel,
	void *outstream_mt,
	size_t outstream_size_mt,
	void *outstream_mt1,
	size_t outstream_size_mt1,
	const uint64_t *inmem_GaussianKernel_GaussianKernelGauss1_mt_seeds0,
	const uint64_t *inmem_GaussianKernel_GaussianKernelGauss_mt_seeds0);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	uint64_t ticks_GaussianKernel; /**<  [in] The number of ticks for which kernel "GaussianKernel" will run. */
	void *outstream_mt; /**<  [out] Stream "mt". */
	size_t outstream_size_mt; /**<  [in] The size of the stream outstream_mt in bytes. */
	void *outstream_mt1; /**<  [out] Stream "mt1". */
	size_t outstream_size_mt1; /**<  [in] The size of the stream outstream_mt1 in bytes. */
	const uint64_t *inmem_GaussianKernel_GaussianKernelGauss1_mt_seeds0; /**<  [in] Mapped ROM inmem_GaussianKernel_GaussianKernelGauss1_mt_seeds0, should be of size (624 * sizeof(uint64_t)). */
	const uint64_t *inmem_GaussianKernel_GaussianKernelGauss_mt_seeds0; /**<  [in] Mapped ROM inmem_GaussianKernel_GaussianKernelGauss_mt_seeds0, should be of size (624 * sizeof(uint64_t)). */
} Gaussian_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void Gaussian_run(
	max_engine_t *engine,
	Gaussian_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Gaussian_run_nonblock(
	max_engine_t *engine,
	Gaussian_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void Gaussian_run_group(max_group_t *group, Gaussian_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Gaussian_run_group_nonblock(max_group_t *group, Gaussian_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void Gaussian_run_array(max_engarray_t *engarray, Gaussian_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Gaussian_run_array_nonblock(max_engarray_t *engarray, Gaussian_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* Gaussian_convert(max_file_t *maxfile, Gaussian_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* Gaussian_init(void);

/* Error handling functions */
int Gaussian_has_errors(void);
const char* Gaussian_get_errors(void);
void Gaussian_clear_errors(void);
/* Free statically allocated maxfile data */
void Gaussian_free(void);
/* These are dummy functions for hardware builds. */
int Gaussian_simulator_start(void);
int Gaussian_simulator_stop(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_Gaussian_H */

