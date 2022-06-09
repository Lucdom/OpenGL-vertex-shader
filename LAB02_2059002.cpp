//  LAB02
//  NOME: LUCAS MAGALHÃES DOMINGUES
//  RA: 2059002

#include <iostream>

//GLEW
#define GLEW_STATIC
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>

//Global Variables
const int gWindowWidth = 800;
const int gWindowHeight = 600;
GLfloat a = 0;
GLfloat b = 0;
GLfloat x = 0;
GLfloat y = 0;
GLfloat z = 0;
const char* TITLE = { "LAB 02" };
GLFWwindow* gWindow = NULL;
bool gWireframe = false;

//Shaders
const GLchar* vertexShaderSrc =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"void main()"
"{"
"   gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);"
"}";

const GLchar* vertexShaderSrc2 =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"void main()"
"{"
"   gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);"
"}";

const GLchar* vertexShaderSrc3 =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"void main()"
"{"
"   gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);"
"}";

const GLchar* vertexShaderSrc4 =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"void main()"
"{"
"   gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);"
"}";

const GLchar* fragmentShaderSrc =
"#version 330 core\n"
"out vec4 frag_color;"
"void main()"
"{"
"    frag_color = vec4(1.0f, 0.0, 0.0f, 0.0f);"
"}";

const GLchar* fragmentShaderSrc2 =
"#version 330 core\n"
"out vec4 frag_color;"
"void main()"
"{"
"    frag_color = vec4(1.0f, 0.9, 0.2f, 0.9f);"
"}";

const GLchar* fragmentShaderSrc3 =
"#version 330 core\n"
"out vec3 frag_color;"
"void main()"
"{"
"    frag_color = vec3(0.1f, 0.0, 0.0f);"
"}";

const GLchar* fragmentShaderSrc4 =
"#version 330 core\n"
"out vec3 frag_color;"
"void main()"
"{"
"    frag_color = vec3(0.5f, 1.0, 1.0f);"
"}";

void glfw_key(GLFWwindow* window, int key, int scancode, int action, int mode);
bool initOpenGL();

int main(void)
{
    
    printf("Utilize as setas para navegar pelo ambiente.\n");
    /*
    printf("Digite as Coordenadas X\n");
    scanf_s("%f", &x);
    printf("Digite as Coordenadas Y\n");
    scanf_s("%f", &y);
    printf("Digite as Coordenadas Z\n");
    scanf_s("%f", &z);
    */

    if (!initOpenGL())
    {
        std::cerr << "Initialization failed" << std::endl;
        return -1;
    }

    GLfloat teto[]{
        0.0f, 1.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
       -0.5f, 0.0f, 0.0f,
    };
    
    GLfloat parede[]{
        0.5f, 0.0f, 0.0f,
        0.5f, -1.0f, 0.0f,
       -0.5f, -1.0f, 0.0f,
       -0.5f, 0.0f, 0.0f,
    };

    GLfloat porta[]{
       -0.1f, -0.0f, 0.0f,
       -0.1f, -1.0f, 0.0f,
       -0.3f, -1.0f, 0.0f,
       -0.3f, -0.0f, 0.0f,
    };

    GLfloat janela[]{
       0.4f, -0.0f, 0.0f,
       0.4f, -0.5f, 0.0f,
       0.0f, -0.5f, 0.0f,
       0.0f, -0.0f, 0.0f,
    };
    
    GLuint iteto[] = {
      0, 0, 0,
    };
    
    GLuint iparede[] = {
      0, 0, 0,
    };
    
    GLuint iporta[] = {
      0, 0, 0,
    };

    GLuint ijanela[] = {
      0, 0, 0,
    };

    //Buffers on the GPU

    GLuint vaoteto;
    glGenVertexArrays(1, &vaoteto);
    glBindVertexArray(vaoteto);

    GLuint vboteto;

    glGenBuffers(1, &vboteto);
    glBindBuffer(GL_ARRAY_BUFFER, vboteto);
    glBufferData(GL_ARRAY_BUFFER, sizeof(teto), teto, GL_STATIC_DRAW);

    GLuint iboteto; //Position attribute

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    GLuint vaoparede;

    glGenVertexArrays(1, &vaoparede);
    glBindVertexArray(vaoparede);

    GLuint vboparede;

    glGenBuffers(1, &vboparede);
    glBindBuffer(GL_ARRAY_BUFFER, vboparede);
    glBufferData(GL_ARRAY_BUFFER, sizeof(parede), parede, GL_STATIC_DRAW);

    GLuint iboparede;

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    GLuint vaoporta;
    glGenVertexArrays(1, &vaoporta);
    glBindVertexArray(vaoporta);

    GLuint vboporta;

    glGenBuffers(1, &vboporta);
    glBindBuffer(GL_ARRAY_BUFFER, vboporta);
    glBufferData(GL_ARRAY_BUFFER, sizeof(porta), porta, GL_STATIC_DRAW);

    GLuint iboporta;

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    GLuint vaojanela;
    glGenVertexArrays(1, &vaojanela);
    glBindVertexArray(vaojanela);

    GLuint vbojanela;

    glGenBuffers(1, &vbojanela);
    glBindBuffer(GL_ARRAY_BUFFER, vbojanela);
    glBufferData(GL_ARRAY_BUFFER, sizeof(janela), janela, GL_STATIC_DRAW);

    GLuint ibojanela;

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    //Create vertex shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexShaderSrc, NULL);
    glCompileShader(vs);

    //Create vertex shader 2
    GLuint vs2 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs2, 1, &vertexShaderSrc2, NULL);
    glCompileShader(vs2);

    //Create vertex shader 3
    GLuint vs3 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs3, 1, &vertexShaderSrc3, NULL);
    glCompileShader(vs3);

    //Create vertex shader 4
    GLuint vs4 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs4, 1, &vertexShaderSrc4, NULL);
    glCompileShader(vs4);

    //Create fragment shader
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderSrc, NULL);
    glCompileShader(fs);

    //Create fragment shader 2
    GLuint fs2 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs2, 1, &fragmentShaderSrc2, NULL);
    glCompileShader(fs2);

    //Create fragment shader 3
    GLuint fs3 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs3, 1, &fragmentShaderSrc3, NULL);
    glCompileShader(fs3);

    //Create fragment shader 4
    GLuint fs4 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs4, 1, &fragmentShaderSrc4, NULL);
    glCompileShader(fs4);

    //Create a program shader
    GLint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vs);
    glAttachShader(shaderProgram, fs);
    glLinkProgram(shaderProgram);

    glDeleteShader(vs);
    glDeleteShader(fs);

    GLint shaderProgram2 = glCreateProgram();
    glAttachShader(shaderProgram2, vs2);
    glAttachShader(shaderProgram2, fs2);
    glLinkProgram(shaderProgram2);

    glDeleteShader(vs2);
    glDeleteShader(fs2);

    GLint shaderProgram3 = glCreateProgram();
    glAttachShader(shaderProgram3, vs3);
    glAttachShader(shaderProgram3, fs3);
    glLinkProgram(shaderProgram3);

    glDeleteShader(vs3);
    glDeleteShader(fs3);

    GLint shaderProgram4 = glCreateProgram();
    glAttachShader(shaderProgram4, vs4);
    glAttachShader(shaderProgram4, fs4);
    glLinkProgram(shaderProgram4);

    glDeleteShader(vs4);
    glDeleteShader(fs4);

    //Entre 0 e 1 - 0 -> preto, 1 - Branco (0 a 255, 0 -> preto, 255 - Branco);
    glClearColor(0.9f, 0.4f, 1.0f, 6.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(gWindow))
    {
        /* Poll for and process events */
        glfwPollEvents();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        //Render the triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(vaoteto);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 360);
        glBindVertexArray(vaoparede);
        glUseProgram(shaderProgram2);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
        glBindVertexArray(vaoporta);
        glUseProgram(shaderProgram3);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
        glBindVertexArray(vaojanela);
        glUseProgram(shaderProgram4);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(gWindow);
    }

    //Clean UP
    glDeleteProgram(shaderProgram);
    glDeleteProgram(shaderProgram2);
    glDeleteProgram(shaderProgram3);
    glDeleteProgram(shaderProgram4);
    glDeleteVertexArrays(1, &vaoteto);
    glDeleteBuffers(1, &vboteto);
    glDeleteVertexArrays(1, &vaoparede);
    glDeleteBuffers(1, &vboparede);
    glDeleteVertexArrays(1, &vaoporta);
    glDeleteBuffers(1, &vboporta);

    glfwTerminate();
    return 0;
}

///
bool initOpenGL()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cerr << "GLFW initialization failed" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //only to support MAC
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    /* Create a windowed mode window and its OpenGL context */
    gWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, TITLE, NULL, NULL);
    if (gWindow == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(gWindow);

    //Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    glfwSetKeyCallback(gWindow, glfw_key);
    return true;
}

void glfw_key(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(gWindow, GL_TRUE);
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        gWireframe = !gWireframe;
        if (gWireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {
        glClearColor(0.9f, 0.5f, 1.0f, 6.0f);
        a = a + 50;
        glViewport(a, b, 800, 600);
    }
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
    {
        glClearColor(0.9f, 0.6f, 1.0f, 6.0f);
        a = a - 50;
        glViewport(a, b, 800, 600);
    }
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        glClearColor(0.9f, 0.7f, 1.0f, 6.0f);
        b = b + 50;
        glViewport(a, b, 800, 600);
    }
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {
       glClearColor(0.9f, 0.72f, 1.0f, 6.0f);
       b = b - 50;
       glViewport(a, b, 800, 600);
    }
    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
    {
        
    }
}