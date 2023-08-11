#pragma once

#include <memory>
#include <vector>

#include "element.h"
#include "token.h"

std::unique_ptr<Element> ParseTokens(const std::vector<Token>& tokens);