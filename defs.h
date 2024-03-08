#pragma once


#define MX_PIGLETS_IMPLEMENT_CLASS_COPY_OPS_DEFAULT(mxPigletsClass)   \
    mxPigletsClass(const mxPigletsClass&) = default;                  \
    mxPigletsClass& operator=(const mxPigletsClass&) = default

#define MX_PIGLETS_IMPLEMENT_CLASS_MOVE_OPS_DEFAULT(mxPigletsClass)   \
    mxPigletsClass(mxPigletsClass&&) = default;                       \
    mxPigletsClass& operator=(mxPigletsClass&&) = default;


#define MX_PIGLETS_IMPLEMENT_CLASS_COPY_OPS_DELETE(mxPigletsClass)   \
    mxPigletsClass(const mxPigletsClass&) = delete;                  \
    mxPigletsClass& operator=(const mxPigletsClass&) = delete

#define MX_PIGLETS_IMPLEMENT_CLASS_MOVE_OPS_DELETE(mxPigletsClass)   \
    mxPigletsClass(mxPigletsClass&&) = delete;                       \
    mxPigletsClass& operator=(mxPigletsClass&&) = delete;


