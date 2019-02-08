//
//  ElementNode.cpp
//  HW1
//
//  Created by Joshua Choi on 2/8/19.
//  Copyright © 2019 Capsule LLC. All rights reserved.
//

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

/**
 Abstract: Custom object used to delegate tasks managing a list better.
 */
class ElementNode {
public:
    /// Initialized Int value used to store the position of this object relative to a list. Defaults to 0.
    int position = 0;
    /// Initialized Int value used to store the value of this object relative to a list. Defaults to null.
    int value = 0;
};

