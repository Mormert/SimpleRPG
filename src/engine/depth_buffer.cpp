#include "depth_buffer.hpp"

#include <raylib.h>

namespace rpg::engine
{
    std::multimap<int, RenderObject> DepthBuffer::buffer{};

    void DepthBuffer::DrawTextureProDepth(int depth, Texture2D texture, Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, Color tint)
    {
        buffer.insert(std::pair<int, RenderObject>(depth, RenderObject{texture, sourceRec, destRec, origin, rotation, tint}));
    }

    void DepthBuffer::ClearBuffer()
    {
        buffer.clear();
    }

    void DepthBuffer::RenderBuffer()
    {
        for (auto const &[depth, renderObject] : buffer)
        {
            DrawTexturePro(renderObject.texture, renderObject.sourceRec, renderObject.destRec, renderObject.origin, renderObject.rotation, renderObject.tint);
        }
    }

} // namespace rpg::engine