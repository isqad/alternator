#ifdef __cplusplus
extern "C" {
#endif

int alternate_ver();

int alternate_init(SPH_UDF_INIT * init, SPH_UDF_ARGS * args, char * error_flag);

void alternate_deinit(SPH_UDF_INIT * init);

sphinx_int64_t alternate(SPH_UDF_INIT * init, SPH_UDF_ARGS * args, char * error_flag);

#ifdef __cplusplus
}
#endif
