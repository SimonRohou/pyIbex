set( SRCS 
			Tube.cpp
			pyIbex_Tube.cpp
		)
set( HEADERS
			Tube.h
		)

add_library(Tube STATIC ${SRCS} ${HEADERS})
target_link_libraries(Tube ${LIBS})