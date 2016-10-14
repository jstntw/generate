#include "window.h"


void checkSDLError(int line = -1) {
#ifdef DEBUG
	const char *error = SDL_GetError();
	if (*error != '\0')
	{
		printf("SDL Error: %s\n", error);
		if (line != -1)
			printf(" + line: %i\n", line);
		SDL_ClearError();
	}
#endif
}


void begin_window(SDL_Window *mainwindow, SDL_GLContext maincontext) {
	/* This makes our buffer swap syncronized with the monitor's vertical refresh */
	SDL_GL_SetSwapInterval(1);

	/* Clear our buffer with a red background */
	glClearColor ( 1.0, 0.0, 0.0, 1.0 );
	glClear ( GL_COLOR_BUFFER_BIT );
	/* Swap our back buffer to the front */
	SDL_GL_SwapWindow(mainwindow);
	/* Wait 2 seconds */
	SDL_Delay(2000);

	/* Same as above, but green */
	glClearColor ( 0.0, 1.0, 0.0, 1.0 );
	glClear ( GL_COLOR_BUFFER_BIT );
	SDL_GL_SwapWindow(mainwindow);
	SDL_Delay(2000);

	/* Same as above, but blue */
	glClearColor ( 0.0, 0.0, 1.0, 1.0 );
	glClear ( GL_COLOR_BUFFER_BIT );
	SDL_GL_SwapWindow(mainwindow);
	SDL_Delay(2000);


}

void setup_context() {
  SDL_Window *mainwindow;
  SDL_GLContext maincontext;
	std::string error;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    error = "Unable to initialize SDL";
		goto exit_window;
	}
  /* Request opengl 3.2 context.
   * SDL doesn't have the ability to choose which profile at this time of writing,
   * but it should default to the core profile */
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

  /* Turn on double buffering with a 24bit Z buffer.
   * You may need to change this to 16 or 32 for your system */
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  mainwindow = SDL_CreateWindow(PROGRAM_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

  if (!mainwindow) {
		error = "Unable to create window";
		goto exit_window;
	}

  // checkSDLError(__LINE__);
  maincontext = SDL_GL_CreateContext(mainwindow);
  // checkSDLError(__LINE__);



	begin_window(mainwindow, maincontext);



	/* Delete our opengl context, destroy our window, and shutdown SDL */
	SDL_GL_DeleteContext(maincontext);
	SDL_DestroyWindow(mainwindow);

	exit_window:
	if(!error.empty())
		std::cout << error << " : " << SDL_GetError() << std::endl;
	SDL_Quit();
}
