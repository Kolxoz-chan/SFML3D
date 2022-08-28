TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        include/SFML3D/Mesh3d.cpp \
        include/SFML3D/View3d.cpp \
        main.cpp

unix|win32: LIBS += -L$$PWD/lib/ -lsfml-system
unix|win32: LIBS += -L$$PWD/lib/ -lsfml-window
unix|win32: LIBS += -L$$PWD/lib/ -lsfml-graphics
unix|win32: LIBS += -L$$PWD/lib/ -lsfml-network
unix|win32: LIBS += -lopengl32

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

DISTFILES += \
    lib/cmake/SFML/SFMLConfig.cmake \
    lib/cmake/SFML/SFMLConfigDependencies.cmake \
    lib/cmake/SFML/SFMLConfigVersion.cmake \
    lib/cmake/SFML/SFMLSharedTargets-debug.cmake \
    lib/cmake/SFML/SFMLSharedTargets-release.cmake \
    lib/cmake/SFML/SFMLSharedTargets.cmake \
    lib/cmake/SFML/SFMLStaticTargets-debug.cmake \
    lib/cmake/SFML/SFMLStaticTargets-release.cmake \
    lib/cmake/SFML/SFMLStaticTargets.cmake \
    lib/flac.lib \
    lib/freetype.lib \
    lib/libsfml-audio.so \
    lib/libsfml-audio.so.2.5 \
    lib/libsfml-audio.so.2.5.1 \
    lib/libsfml-graphics.so \
    lib/libsfml-graphics.so.2.5 \
    lib/libsfml-graphics.so.2.5.1 \
    lib/libsfml-network.so \
    lib/libsfml-network.so.2.5 \
    lib/libsfml-network.so.2.5.1 \
    lib/libsfml-system.so \
    lib/libsfml-system.so.2.5 \
    lib/libsfml-system.so.2.5.1 \
    lib/libsfml-window.so \
    lib/libsfml-window.so.2.5 \
    lib/libsfml-window.so.2.5.1 \
    lib/ogg.lib \
    lib/openal32.lib \
    lib/sfml-audio-d.lib \
    lib/sfml-audio-d.pdb \
    lib/sfml-audio-s-d.lib \
    lib/sfml-audio-s-d.pdb \
    lib/sfml-audio-s.lib \
    lib/sfml-audio.lib \
    lib/sfml-graphics-d.lib \
    lib/sfml-graphics-d.pdb \
    lib/sfml-graphics-s-d.lib \
    lib/sfml-graphics-s-d.pdb \
    lib/sfml-graphics-s.lib \
    lib/sfml-graphics.lib \
    lib/sfml-main-d.lib \
    lib/sfml-main-s-d.pdb \
    lib/sfml-main.lib \
    lib/sfml-network-d.lib \
    lib/sfml-network-d.pdb \
    lib/sfml-network-s-d.lib \
    lib/sfml-network-s-d.pdb \
    lib/sfml-network-s.lib \
    lib/sfml-network.lib \
    lib/sfml-system-d.lib \
    lib/sfml-system-d.pdb \
    lib/sfml-system-s-d.lib \
    lib/sfml-system-s-d.pdb \
    lib/sfml-system-s.lib \
    lib/sfml-system.lib \
    lib/sfml-window-d.lib \
    lib/sfml-window-d.pdb \
    lib/sfml-window-s-d.lib \
    lib/sfml-window-s-d.pdb \
    lib/sfml-window-s.lib \
    lib/sfml-window.lib \
    lib/vorbis.lib \
    lib/vorbisenc.lib \
    lib/vorbisfile.lib \
    resources/background.jpg \
    resources/sansation.ttf \
    resources/texture.jpg \
    test.mtl

HEADERS += \
    include/SFML/Audio.hpp \
    include/SFML/Audio/AlResource.hpp \
    include/SFML/Audio/Export.hpp \
    include/SFML/Audio/InputSoundFile.hpp \
    include/SFML/Audio/Listener.hpp \
    include/SFML/Audio/Music.hpp \
    include/SFML/Audio/OutputSoundFile.hpp \
    include/SFML/Audio/Sound.hpp \
    include/SFML/Audio/SoundBuffer.hpp \
    include/SFML/Audio/SoundBufferRecorder.hpp \
    include/SFML/Audio/SoundFileFactory.hpp \
    include/SFML/Audio/SoundFileFactory.inl \
    include/SFML/Audio/SoundFileReader.hpp \
    include/SFML/Audio/SoundFileWriter.hpp \
    include/SFML/Audio/SoundRecorder.hpp \
    include/SFML/Audio/SoundSource.hpp \
    include/SFML/Audio/SoundStream.hpp \
    include/SFML/Config.hpp \
    include/SFML/GpuPreference.hpp \
    include/SFML/Graphics.hpp \
    include/SFML/Graphics/BlendMode.hpp \
    include/SFML/Graphics/CircleShape.hpp \
    include/SFML/Graphics/Color.hpp \
    include/SFML/Graphics/ConvexShape.hpp \
    include/SFML/Graphics/Drawable.hpp \
    include/SFML/Graphics/Export.hpp \
    include/SFML/Graphics/Font.hpp \
    include/SFML/Graphics/Glsl.hpp \
    include/SFML/Graphics/Glsl.inl \
    include/SFML/Graphics/Glyph.hpp \
    include/SFML/Graphics/Image.hpp \
    include/SFML/Graphics/PrimitiveType.hpp \
    include/SFML/Graphics/Rect.hpp \
    include/SFML/Graphics/Rect.inl \
    include/SFML/Graphics/RectangleShape.hpp \
    include/SFML/Graphics/RenderStates.hpp \
    include/SFML/Graphics/RenderTarget.hpp \
    include/SFML/Graphics/RenderTexture.hpp \
    include/SFML/Graphics/RenderWindow.hpp \
    include/SFML/Graphics/Shader.hpp \
    include/SFML/Graphics/Shape.hpp \
    include/SFML/Graphics/Sprite.hpp \
    include/SFML/Graphics/Text.hpp \
    include/SFML/Graphics/Texture.hpp \
    include/SFML/Graphics/Transform.hpp \
    include/SFML/Graphics/Transformable.hpp \
    include/SFML/Graphics/Vertex.hpp \
    include/SFML/Graphics/VertexArray.hpp \
    include/SFML/Graphics/VertexBuffer.hpp \
    include/SFML/Graphics/View.hpp \
    include/SFML/Main.hpp \
    include/SFML/Network.hpp \
    include/SFML/Network/Export.hpp \
    include/SFML/Network/Ftp.hpp \
    include/SFML/Network/Http.hpp \
    include/SFML/Network/IpAddress.hpp \
    include/SFML/Network/Packet.hpp \
    include/SFML/Network/Socket.hpp \
    include/SFML/Network/SocketHandle.hpp \
    include/SFML/Network/SocketSelector.hpp \
    include/SFML/Network/TcpListener.hpp \
    include/SFML/Network/TcpSocket.hpp \
    include/SFML/Network/UdpSocket.hpp \
    include/SFML/OpenGL.hpp \
    include/SFML/System.hpp \
    include/SFML/System/Clock.hpp \
    include/SFML/System/Err.hpp \
    include/SFML/System/Export.hpp \
    include/SFML/System/FileInputStream.hpp \
    include/SFML/System/InputStream.hpp \
    include/SFML/System/Lock.hpp \
    include/SFML/System/MemoryInputStream.hpp \
    include/SFML/System/Mutex.hpp \
    include/SFML/System/NativeActivity.hpp \
    include/SFML/System/NonCopyable.hpp \
    include/SFML/System/Sleep.hpp \
    include/SFML/System/String.hpp \
    include/SFML/System/String.inl \
    include/SFML/System/Thread.hpp \
    include/SFML/System/Thread.inl \
    include/SFML/System/ThreadLocal.hpp \
    include/SFML/System/ThreadLocalPtr.hpp \
    include/SFML/System/ThreadLocalPtr.inl \
    include/SFML/System/Time.hpp \
    include/SFML/System/Utf.hpp \
    include/SFML/System/Utf.inl \
    include/SFML/System/Vector2.hpp \
    include/SFML/System/Vector2.inl \
    include/SFML/System/Vector3.hpp \
    include/SFML/System/Vector3.inl \
    include/SFML/Window.hpp \
    include/SFML/Window/Clipboard.hpp \
    include/SFML/Window/Context.hpp \
    include/SFML/Window/ContextSettings.hpp \
    include/SFML/Window/Cursor.hpp \
    include/SFML/Window/Event.hpp \
    include/SFML/Window/Export.hpp \
    include/SFML/Window/GlResource.hpp \
    include/SFML/Window/Joystick.hpp \
    include/SFML/Window/Keyboard.hpp \
    include/SFML/Window/Mouse.hpp \
    include/SFML/Window/Sensor.hpp \
    include/SFML/Window/Touch.hpp \
    include/SFML/Window/VideoMode.hpp \
    include/SFML/Window/Window.hpp \
    include/SFML/Window/WindowHandle.hpp \
    include/SFML/Window/WindowStyle.hpp \
    include/SFML3D/Mesh3d.h \
    include/SFML3D/View3d.h
