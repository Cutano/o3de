#
# Copyright (c) Contributors to the Open 3D Engine Project.
# For complete copyright and license terms please see the LICENSE at the root of this distribution.
#
# SPDX-License-Identifier: Apache-2.0 OR MIT
#
#

set(FILES
    Source/RecastNavigationModuleInterface.h
    Source/RecastNavigationSystemComponent.cpp
    Source/RecastNavigationSystemComponent.h

    Source/Components/DetourNavigationComponent.h
    Source/Components/DetourNavigationComponent.cpp
    Source/Components/RecastNavigationMeshComponent.h
    Source/Components/RecastNavigationMeshComponent.cpp
    Source/Components/RecastNavigationPhysXProviderComponent.h
    Source/Components/RecastNavigationPhysXProviderComponent.cpp

    Source/Misc/RecastHelpers.h
    Source/Misc/RecastNavigationDebugDraw.h
    Source/Misc/RecastNavigationDebugDraw.cpp
    Source/Misc/RecastNavigationMeshCommon.h
    Source/Misc/RecastNavigationMeshCommon.cpp
    Source/Misc/RecastNavigationMeshConfig.h
    Source/Misc/RecastNavigationMeshConfig.cpp
    Source/Misc/RecastNavigationPhysXProviderCommon.h
    Source/Misc/RecastNavigationPhysXProviderCommon.cpp
    Source/Misc/RecastSmartPointer.h
)
