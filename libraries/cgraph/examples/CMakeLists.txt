add_executable(cgraph_ivec_t_demo cgraph_ivec_t_demo.c)
add_executable(cvector_demo cvector_demo.c)
add_executable(ivec_as_param cgraph_ivec_as_param_demo.c)
add_executable(ivec_as_param2 cgraph_ivec_as_param_demo2.c)
add_executable(cgraph_rvec_t_demo cgraph_rvec_t_demo.c)
add_executable(create_graph_demo create_graph_demo.c)

foreach(t cgraph_ivec_t_demo cgraph_rvec_t_demo ivec_as_param ivec_as_param2 create_graph_demo)
  target_link_libraries(${t} cgraph)
endforeach()

add_subdirectory(ctc)
add_subdirectory(application)
add_subdirectory(cgen)
add_subdirectory(bus)