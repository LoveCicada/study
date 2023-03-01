#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image_ex.h"
#include "Shader.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

/*
* @brief glfw常用回调事件
* @see https://www.caxkernel.com/6046.html
* 1. 按键输入
* 2. 字符输入
* 3. 组合键输入
* 4. 鼠标按键触发
* 5. 光标移动触发
* 6. 光标进入/离开触发
* 7. 鼠标滚轮触发
*/

// 按键输入
static void KeyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

// 字符输入
static void CharInputCallback(GLFWwindow* window, unsigned int codepoint);

// 组合键输入
static void CharModCallback(GLFWwindow* window, unsigned int codepoint, int mods);

// 鼠标按键触发
static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

// 光标移动触发
static void CursorposCallback(GLFWwindow* window, double xpos, double ypos);

// 光标进入/离开触发
static void CursorEnterCallback(GLFWwindow* window, int entered);

// 鼠标滚轮触发
static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
   
    ////////////////////////////////////
    glfwSetKeyCallback(window, KeyInputCallback);
    glfwSetCharCallback(window, CharInputCallback);
    glfwSetCharModsCallback(window, CharModCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetCursorPosCallback(window, CursorposCallback);
    glfwSetCursorEnterCallback(window, CursorEnterCallback);
    glfwSetScrollCallback(window, ScrollCallback);
    //////////////////////////////////

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("4.1.texture.vs", "4.1.texture.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    // load and create a texture 
    // -------------------------
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char* data = stbi_load("jojo.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);

        // render container
        ourShader.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void KeyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << __FUNCTION__ << std::endl;
}

void CharInputCallback(GLFWwindow* window, unsigned int codepoint)
{
    std::cout << __FUNCTION__ << std::endl;
}

void CharModCallback(GLFWwindow* window, unsigned int codepoint, int mods)
{
    std::cout << __FUNCTION__ << std::endl;
}

void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    std::string strMouseLeftBtn = " Mouse Left Button ";
    std::string strMouseRightBtn = " Mouse Right Button ";
    std::string strMouseMidBtn = " Mouse Mid Button ";
    std::string strMouseType;

    if (0 == button)
    {
        strMouseType += strMouseLeftBtn;
    }
    else if (1 == button)
    {
        strMouseType += strMouseRightBtn;
    }
    else if (2 == button)
    {
        strMouseType += strMouseMidBtn;
    }
    else
    {
        std::cout << __FUNCTION__ << " unknown button type" << std::endl;
    }

    std::string strMousePress = "Press";
    std::string strMouseRelease = "Release";
    std::string strMouseStatus;
    if (0 == action)
    {
        strMouseStatus += strMousePress;
    }
    else if (1 == action)
    {
        strMouseStatus += strMouseRelease;
    }
    else
    {
        std::cout << __FUNCTION__ << " unknown button status" << std::endl;
    }

    std::cout << __FUNCTION__ << strMouseType + strMouseStatus << std::endl;

    

}

void CursorposCallback(GLFWwindow* window, double xpos, double ypos)
{
    std::cout << __FUNCTION__ << std::endl;
}

void CursorEnterCallback(GLFWwindow* window, int entered)
{
    std::string strCursorLeaveStatus = " leave ";
    std::string strCursorEnterStatus = " enter ";
    std::string strCursorEnterType;

    if (0 == entered)
    {
        strCursorEnterType += strCursorLeaveStatus;
    }
    else if (1 == entered)
    {
        strCursorEnterType += strCursorEnterStatus;
    }
    else
    {
        std::cout << __FUNCTION__ << " unknown cursor status" << std::endl;
    }


    std::cout << __FUNCTION__ << strCursorEnterType << std::endl;
}

void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    std::cout << __FUNCTION__ << std::endl;
}