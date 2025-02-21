SoLong: 42 school assignment about creating a simple 2D game using MiniLibX. I chose this project for it's simplicity and for fun. I considered making Fractol (visual project about creating fractals), but fractals make me dizzy.

Project start: 29.10.

Goal: Understand what this project and minilibx is about, create a Makefile and project folder.

Outcome: Decided to use Codam's creation MLX42 instead or MiniLibX, as many suggested it's just clearer, better and updated.
Created a Makefile which clones MLX42 repo and builds the library if those steps aren't already done. It also prompts the user to install necessary packages in case they're not installed. This is for Linux-environment.

Project Norminetted and close to finish: 11.11.

/**
 * Generic loop hook for any custom hooks to add to the main loop. 
 * Executes a function per frame, so be careful.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] f The function.
 * @param[in] param The parameter to pass on to the function.
 * @returns Whether or not the hook was added successfully. 
 */
//bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);



/**
 * Initializes the rendering of MLX, this function won't return until
 * mlx_close_window is called, meaning it will loop until the user requests that
 * the window should close.
 * 
 * @param[in] mlx The MLX instance handle.
 */
///void mlx_loop(mlx_t* mlx);



/**
 * Notifies MLX that it should stop rendering and exit the main loop.
 * This is not the same as terminate, this simply tells MLX to close the window.
 * 
 * @param[in] mlx The MLX instance handle.
 */
//void mlx_close_window(mlx_t* mlx);



/**
 * This function sets the close callback, which is called in attempt to close 
 * the window device such as a close window widget used in the window bar.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The close callback function.
 * @param[in] param An additional optional parameter.
 */
//void mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param);
