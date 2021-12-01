/*
 * Copyright (c) 2021, Stephan Unverwerth <s.unverwerth@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include "Clipper.h"
#include "GLContext.h"
#include "GLStruct.h"
#include "SoftwareRasterizer.h"
#include "Tex/NameAllocator.h"
#include "Tex/Texture.h"
#include "Tex/TextureUnit.h"
#include <AK/HashMap.h>
#include <AK/RefPtr.h>
#include <AK/Tuple.h>
#include <AK/Variant.h>
#include <AK/Vector.h>
#include <LibGfx/Bitmap.h>
#include <LibGfx/Matrix4x4.h>
#include <LibGfx/Rect.h>
#include <LibGfx/Vector3.h>

namespace GL {

class SoftwareGLContext : public GLContext {
public:
    SoftwareGLContext(Gfx::Bitmap&);

    virtual void gl_begin(GLenum mode) override;
    virtual void gl_clear(GLbitfield mask) override;
    virtual void gl_clear_color(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) override;
    virtual void gl_clear_depth(GLdouble depth) override;
    virtual void gl_clear_stencil(GLint s) override;
    virtual void gl_color(GLdouble r, GLdouble g, GLdouble b, GLdouble a) override;
    virtual void gl_delete_textures(GLsizei n, const GLuint* textures) override;
    virtual void gl_end() override;
    virtual void gl_frustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val) override;
    virtual void gl_gen_textures(GLsizei n, GLuint* textures) override;
    virtual GLenum gl_get_error() override;
    virtual GLubyte* gl_get_string(GLenum name) override;
    virtual void gl_load_identity() override;
    virtual void gl_load_matrix(const FloatMatrix4x4& matrix) override;
    virtual void gl_matrix_mode(GLenum mode) override;
    virtual void gl_ortho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val) override;
    virtual void gl_push_matrix() override;
    virtual void gl_pop_matrix() override;
    virtual void gl_mult_matrix(FloatMatrix4x4 const& matrix) override;
    virtual void gl_rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) override;
    virtual void gl_scale(GLdouble x, GLdouble y, GLdouble z) override;
    virtual void gl_translate(GLdouble x, GLdouble y, GLdouble z) override;
    virtual void gl_vertex(GLdouble x, GLdouble y, GLdouble z, GLdouble w) override;
    virtual void gl_viewport(GLint x, GLint y, GLsizei width, GLsizei height) override;
    virtual void gl_enable(GLenum) override;
    virtual void gl_disable(GLenum) override;
    virtual GLboolean gl_is_enabled(GLenum) override;
    virtual void gl_front_face(GLenum) override;
    virtual void gl_cull_face(GLenum) override;
    virtual GLuint gl_gen_lists(GLsizei range) override;
    virtual void gl_call_list(GLuint list) override;
    virtual void gl_call_lists(GLsizei n, GLenum type, void const* lists) override;
    virtual void gl_delete_lists(GLuint list, GLsizei range) override;
    virtual void gl_list_base(GLuint base) override;
    virtual void gl_end_list(void) override;
    virtual void gl_new_list(GLuint list, GLenum mode) override;
    virtual GLboolean gl_is_list(GLuint list) override;
    virtual void gl_flush() override;
    virtual void gl_finish() override;
    virtual void gl_blend_func(GLenum src_factor, GLenum dst_factor) override;
    virtual void gl_shade_model(GLenum mode) override;
    virtual void gl_alpha_func(GLenum func, GLclampf ref) override;
    virtual void gl_hint(GLenum target, GLenum mode) override;
    virtual void gl_read_buffer(GLenum mode) override;
    virtual void gl_draw_buffer(GLenum buffer) override;
    virtual void gl_read_pixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels) override;
    virtual void gl_tex_image_2d(GLenum target, GLint level, GLint internal_format, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data) override;
    virtual void gl_tex_sub_image_2d(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* data) override;
    virtual void gl_tex_parameter(GLenum target, GLenum pname, GLfloat param) override;
    virtual void gl_tex_coord(GLfloat s, GLfloat t, GLfloat r, GLfloat q) override;
    virtual void gl_tex_env(GLenum target, GLenum pname, GLfloat param) override;
    virtual void gl_bind_texture(GLenum target, GLuint texture) override;
    virtual void gl_active_texture(GLenum texture) override;
    virtual void gl_depth_mask(GLboolean flag) override;
    virtual void gl_enable_client_state(GLenum cap) override;
    virtual void gl_disable_client_state(GLenum cap) override;
    virtual void gl_vertex_pointer(GLint size, GLenum type, GLsizei stride, const void* pointer) override;
    virtual void gl_color_pointer(GLint size, GLenum type, GLsizei stride, const void* pointer) override;
    virtual void gl_tex_coord_pointer(GLint size, GLenum type, GLsizei stride, const void* pointer) override;
    virtual void gl_draw_arrays(GLenum mode, GLint first, GLsizei count) override;
    virtual void gl_draw_elements(GLenum mode, GLsizei count, GLenum type, const void* indices) override;
    virtual void gl_draw_pixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void* data) override;
    virtual void gl_color_mask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) override;
    virtual void gl_get_booleanv(GLenum pname, GLboolean* data) override;
    virtual void gl_get_doublev(GLenum pname, GLdouble* params) override;
    virtual void gl_get_floatv(GLenum pname, GLfloat* params) override;
    virtual void gl_get_integerv(GLenum pname, GLint* data) override;
    virtual void gl_depth_range(GLdouble min, GLdouble max) override;
    virtual void gl_depth_func(GLenum func) override;
    virtual void gl_polygon_mode(GLenum face, GLenum mode) override;
    virtual void gl_polygon_offset(GLfloat factor, GLfloat units) override;
    virtual void gl_fogfv(GLenum pname, GLfloat* params) override;
    virtual void gl_fogf(GLenum pname, GLfloat param) override;
    virtual void gl_fogi(GLenum pname, GLint param) override;
    virtual void gl_pixel_storei(GLenum pname, GLint param) override;
    virtual void gl_scissor(GLint x, GLint y, GLsizei width, GLsizei height) override;
    virtual void gl_stencil_func_separate(GLenum face, GLenum func, GLint ref, GLuint mask) override;
    virtual void gl_stencil_op_separate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) override;
    virtual void gl_normal(GLfloat nx, GLfloat ny, GLfloat nz) override;
    virtual void gl_raster_pos(GLfloat x, GLfloat y, GLfloat z, GLfloat w) override;
    virtual void gl_materialv(GLenum face, GLenum pname, GLfloat const* params) override;
    virtual void gl_line_width(GLfloat width) override;
    virtual void gl_push_attrib(GLbitfield mask) override;
    virtual void gl_pop_attrib() override;
    virtual void gl_light_model(GLenum pname, GLfloat x, GLfloat y, GLfloat z, GLfloat w) override;
    virtual void gl_bitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte const* bitmap) override;
    virtual void present() override;

private:
    template<typename T>
    T* store_in_listing(T value)
    {
        VERIFY(m_current_listing_index.has_value());
        auto& listing = m_current_listing_index->listing;
        listing.saved_arguments.empend(make<Listing::ExtraSavedArguments>(move(value)));
        return listing.saved_arguments.last()->template get_pointer<T>();
    }

    template<auto member, typename... Args>
    void append_to_listing(Args&&... args)
    {
        VERIFY(m_current_listing_index.has_value());
        m_current_listing_index->listing.entries.empend(member, Listing::ArgumentsFor<member> { forward<Args>(args)... });
    }

    template<typename T>
    void get_floating_point(GLenum pname, T* params);

    void invoke_list(size_t list_index);
    [[nodiscard]] bool should_append_to_listing() const { return m_current_listing_index.has_value(); }
    [[nodiscard]] bool should_execute_after_appending_to_listing() const { return m_current_listing_index.has_value() && m_current_listing_index->mode == GL_COMPILE_AND_EXECUTE; }

    GLenum m_current_draw_mode;
    GLenum m_current_matrix_mode;
    FloatMatrix4x4 m_projection_matrix = FloatMatrix4x4::identity();
    FloatMatrix4x4 m_model_view_matrix = FloatMatrix4x4::identity();
    FloatMatrix4x4 m_current_matrix = FloatMatrix4x4::identity();

    Vector<FloatMatrix4x4> m_projection_matrix_stack;
    Vector<FloatMatrix4x4> m_model_view_matrix_stack;

    FloatVector4 m_clear_color { 0.0f, 0.0f, 0.0f, 0.0f };
    double m_clear_depth { 1.0 };
    GLint m_clear_stencil { 0 };

    FloatVector4 m_current_vertex_color = { 1.0f, 1.0f, 1.0f, 1.0f };
    FloatVector4 m_current_vertex_tex_coord = { 0.0f, 0.0f, 0.0f, 0.0f };
    FloatVector3 m_current_vertex_normal = { 0.0f, 0.0f, 1.0f };

    Vector<GLVertex, 96> vertex_list;
    Vector<GLTriangle, 32> triangle_list;
    Vector<GLTriangle, 32> processed_triangles;
    Vector<GLVertex> m_clipped_vertices;

    GLenum m_error = GL_NO_ERROR;
    bool m_in_draw_state = false;

    bool m_depth_test_enabled = false;

    bool m_cull_faces = false;
    GLenum m_front_face = GL_CCW;
    GLenum m_culled_sides = GL_BACK;

    bool m_blend_enabled = false;
    GLenum m_blend_source_factor = GL_ONE;
    GLenum m_blend_destination_factor = GL_ZERO;

    bool m_alpha_test_enabled = false;
    GLenum m_alpha_test_func = GL_ALWAYS;
    GLclampf m_alpha_test_ref_value = 0;

    // Stencil configuration
    bool m_stencil_test_enabled { false };

    struct StencilFunctionOptions {
        GLenum func { GL_ALWAYS };
        GLint reference_value { 0 };
        GLuint mask { NumericLimits<GLuint>::max() };
    };
    StencilFunctionOptions m_stencil_backfacing_func;
    StencilFunctionOptions m_stencil_frontfacing_func;

    struct StencilOperationOptions {
        GLenum op_fail { GL_KEEP };
        GLenum op_depth_fail { GL_KEEP };
        GLenum op_pass { GL_KEEP };
    };
    StencilOperationOptions m_stencil_backfacing_op;
    StencilOperationOptions m_stencil_frontfacing_op;

    GLenum m_current_read_buffer = GL_BACK;
    GLenum m_current_draw_buffer = GL_BACK;

    // Client side arrays
    bool m_client_side_vertex_array_enabled = false;
    bool m_client_side_color_array_enabled = false;
    bool m_client_side_texture_coord_array_enabled = false;

    NonnullRefPtr<Gfx::Bitmap> m_frontbuffer;

    Clipper m_clipper;

    // Texture objects
    TextureNameAllocator m_name_allocator;
    HashMap<GLuint, RefPtr<Texture>> m_allocated_textures;
    Array<TextureUnit, 32> m_texture_units;
    TextureUnit* m_active_texture_unit { &m_texture_units[0] };

    SoftwareRasterizer m_rasterizer;

    struct Listing {

        template<typename F>
        struct TupleTypeForArgumentListOf_;

        template<typename Ret, typename C, typename... Args>
        struct TupleTypeForArgumentListOf_<Ret (C::*)(Args...)> {
            using Type = Tuple<Args...>;
        };

        template<typename F>
        using TupleTypeForArgumentListOf = typename TupleTypeForArgumentListOf_<F>::Type;

        template<auto member>
        using ArgumentsFor = TupleTypeForArgumentListOf<decltype(member)>;

        template<typename... Fns>
        struct FunctionAndArgs {
            Variant<Fns...> function;
            Variant<TupleTypeForArgumentListOf<Fns>...> arguments;
        };

        using FunctionsAndArgs = FunctionAndArgs<
            decltype(&SoftwareGLContext::gl_begin),
            decltype(&SoftwareGLContext::gl_clear),
            decltype(&SoftwareGLContext::gl_clear_color),
            decltype(&SoftwareGLContext::gl_clear_depth),
            decltype(&SoftwareGLContext::gl_clear_stencil),
            decltype(&SoftwareGLContext::gl_color),
            decltype(&SoftwareGLContext::gl_end),
            decltype(&SoftwareGLContext::gl_frustum),
            decltype(&SoftwareGLContext::gl_load_identity),
            decltype(&SoftwareGLContext::gl_load_matrix),
            decltype(&SoftwareGLContext::gl_matrix_mode),
            decltype(&SoftwareGLContext::gl_ortho),
            decltype(&SoftwareGLContext::gl_push_matrix),
            decltype(&SoftwareGLContext::gl_pop_matrix),
            decltype(&SoftwareGLContext::gl_mult_matrix),
            decltype(&SoftwareGLContext::gl_rotate),
            decltype(&SoftwareGLContext::gl_scale),
            decltype(&SoftwareGLContext::gl_translate),
            decltype(&SoftwareGLContext::gl_vertex),
            decltype(&SoftwareGLContext::gl_viewport),
            decltype(&SoftwareGLContext::gl_enable),
            decltype(&SoftwareGLContext::gl_disable),
            decltype(&SoftwareGLContext::gl_front_face),
            decltype(&SoftwareGLContext::gl_cull_face),
            decltype(&SoftwareGLContext::gl_call_list),
            decltype(&SoftwareGLContext::gl_call_lists),
            decltype(&SoftwareGLContext::gl_blend_func),
            decltype(&SoftwareGLContext::gl_shade_model),
            decltype(&SoftwareGLContext::gl_alpha_func),
            decltype(&SoftwareGLContext::gl_hint),
            decltype(&SoftwareGLContext::gl_read_buffer),
            decltype(&SoftwareGLContext::gl_tex_parameter),
            decltype(&SoftwareGLContext::gl_depth_mask),
            decltype(&SoftwareGLContext::gl_draw_arrays),
            decltype(&SoftwareGLContext::gl_draw_elements),
            decltype(&SoftwareGLContext::gl_draw_pixels),
            decltype(&SoftwareGLContext::gl_depth_range),
            decltype(&SoftwareGLContext::gl_polygon_offset),
            decltype(&SoftwareGLContext::gl_scissor),
            decltype(&SoftwareGLContext::gl_stencil_func_separate),
            decltype(&SoftwareGLContext::gl_stencil_op_separate),
            decltype(&SoftwareGLContext::gl_normal),
            decltype(&SoftwareGLContext::gl_raster_pos),
            decltype(&SoftwareGLContext::gl_materialv),
            decltype(&SoftwareGLContext::gl_line_width),
            decltype(&SoftwareGLContext::gl_push_attrib),
            decltype(&SoftwareGLContext::gl_pop_attrib),
            decltype(&SoftwareGLContext::gl_light_model),
            decltype(&SoftwareGLContext::gl_bitmap)>;

        using ExtraSavedArguments = Variant<
            FloatMatrix4x4>;

        Vector<NonnullOwnPtr<ExtraSavedArguments>> saved_arguments;
        Vector<FunctionsAndArgs> entries;
    };

    static constexpr size_t max_allowed_gl_call_depth { 128 };
    size_t m_gl_call_depth { 0 };
    Vector<Listing> m_listings;
    size_t m_list_base { 0 };
    struct CurrentListing {
        Listing listing;
        size_t index { 0 };
        GLenum mode { GL_COMPILE };
    };
    Optional<CurrentListing> m_current_listing_index;

    struct VertexAttribPointer {
        GLint size { 4 };
        GLenum type { GL_FLOAT };
        GLsizei stride { 0 };
        const void* pointer { 0 };
    };

    static void read_from_vertex_attribute_pointer(VertexAttribPointer const&, int index, float* elements, bool normalize);

    VertexAttribPointer m_client_vertex_pointer;
    VertexAttribPointer m_client_color_pointer;
    VertexAttribPointer m_client_tex_coord_pointer;

    u8 m_pack_alignment { 4 };
    GLsizei m_unpack_row_length { 0 };
    u8 m_unpack_alignment { 4 };

    struct RasterPosition {
        FloatVector3 window_coordinates { 0.0f, 0.0f, 0.0f };
        float clip_coordinate_value { 1.0f };
        float eye_coordinate_distance { 0.0f };
        bool valid { true };
        FloatVector4 color_rgba { 1.0f, 1.0f, 1.0f, 1.0f };
        float color_index { 1.0f };
        FloatVector4 texture_coordinates { 0.0f, 0.0f, 0.0f, 1.0f };
    };
    RasterPosition m_current_raster_position;

    float m_line_width { 1.0f };

    FloatVector4 m_light_model_ambient { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat m_light_model_two_side { 0.0f };
};

}
