<h1> This is a simple maze game.</h1> 


	' ' is empty place, you can go there.
	'#' is wall.
	's' is starting point.
	'e' is ending point.
	'p' shows where you are.

you can go up, left, down, right with wasd.

but, you want to change the shape of maze, you can use add ' and ,.<br>
write the shape of maze with SizeofMaze.<br>
  like this.<br>

	5
	#####
	#   #
	# # #
	#e#s#
	#####
and play the add'and,.cpp.
It make 'output.txt' like this.

	'#','#','#','#','#','#',' ',' ',' ','#','#',' ','#',' ','#','#','e','#','s','#','#','#','#','#','#',

Copy without the latest ',' and paste them in the array, 'OriginalMaze'.<br>
and change the scale of arry and var of 'SizeofMaze'(int).<br>

if you change your ablity of eyes, change 'VisionDistance'.

	##############################
	#e                           #
	############################ #
	# #           #   #    #     #
	# # ######### # #   #     #  #
	# #           # ##############
	# ########### #              #
	# #         # ############## #
	# #  ###### # #            # #
	# #  ##   # # # ########## # #
	# #   # # # # # #   #   ## # #
	# # # # # # # # # #   #    # #
	# # # # # # # # # ########## #
	# # #       # # #            #
	# # ######### # ##############
	# #           #     #        #
	# # ######### ##### # ###### #
	# # # #     # #     # #    # #
	# # # # ### # # ### # # ## # #
	# # # # ##### # #   # #### # #
	# # # #       # #####    # # #
	# # #   #######    ##### # # #
	# # # #   ########     # # # #
	# # # #####   #   #   ## # # #
	# # #       #   #   #  # # # #
	# # #################### # # #
	# #                        # #
	# ########################## #
	#                           s#
	##############################
