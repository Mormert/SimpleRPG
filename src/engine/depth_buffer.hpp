#ifndef RPG_ENGINE_DEPTH_BUFFER
#define RPG_ENGINE_DEPTH_BUFFER

#include <raylib.h>

#include <map>

namespace rpg::engine
{

    struct RenderObject
    {
        Texture2D texture;
        Rectangle sourceRec;
        Rectangle destRec;
        Vector2 origin;
        float rotation;
        Color tint;
    };

    class DepthBuffer
    {
    private:
        // TODO : Using std::multimap has terrible performance,
        // prefer using array with indexing perhaps
        static std::multimap<int, RenderObject> buffer;

    public:
        static void DrawTextureProDepth(int depth, Texture2D texture, Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, Color tint);
        static void ClearBuffer();
        static void RenderBuffer();
    };

} // namespace rpg::engine

#endif // RPG_ENGINE_DEPTH_BUFFER