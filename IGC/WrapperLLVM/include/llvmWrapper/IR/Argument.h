/*===================== begin_copyright_notice ==================================

Copyright (c) 2017 Intel Corporation

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


======================= end_copyright_notice ==================================*/

#ifndef IGCLLVM_IR_ARGUMENT_H
#define IGCLLVM_IR_ARGUMENT_H

#include "Attributes.h"
#include <llvm/IR/Argument.h>

namespace IGCLLVM
{
	inline void ArgumentAddAttr(llvm::Argument& Arg, unsigned Index, llvm::Attribute::AttrKind Attr)
	{
		IGCLLVM::AttributeSet attrSet = IGCLLVM::AttributeSet::get(
			Arg.getParent()->getContext(),
			Index,
			Attr);
#if LLVM_VERSION_MAJOR == 4
		Arg.addAttr(attrSet);
#elif LLVM_VERSION_MAJOR >= 7
		Arg.addAttr(attrSet.getAttribute(Index, Attr));
#endif
	}
}

#endif