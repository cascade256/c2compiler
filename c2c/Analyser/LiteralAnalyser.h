/* Copyright 2013 Bas van den Berg
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LITERAL_ANALYSER_H
#define LITERAL_ANALYSER_H

#include <llvm/ADT/APSInt.h>

#include "AST/Type.h"

namespace clang {
class DiagnosticsEngine;
}

namespace C2 {

class Expr;

class LiteralAnalyser {
public:
    LiteralAnalyser(clang::DiagnosticsEngine& Diags_);

    QualType check(QualType TLeft, QualType TRight, Expr* Right);
private:
    llvm::APSInt checkLiterals(QualType TLeft, QualType TRight, Expr* Right, llvm::APSInt& Result);
    llvm::APSInt checkIntegerLiterals(QualType TLeft, QualType TRight, Expr* Right, llvm::APSInt& Result);
    llvm::APSInt checkUnaryLiterals(QualType TLeft, QualType TRight, Expr* Right, llvm::APSInt& Result);
    llvm::APSInt checkBinaryLiterals(QualType TLeft, QualType TRight, Expr* Right, llvm::APSInt& Result);
    llvm::APSInt checkIdentifier(QualType TLeft, QualType TRight, Expr* Right, llvm::APSInt& Result);

    clang::DiagnosticsEngine& Diags;

    LiteralAnalyser(const LiteralAnalyser&);
    LiteralAnalyser& operator= (const LiteralAnalyser&);
};

}

#endif
