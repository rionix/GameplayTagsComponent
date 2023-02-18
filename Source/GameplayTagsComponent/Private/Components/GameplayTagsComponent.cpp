// Copyright (c) 2003-2023 Rionix, Ltd. All Rights Reserved.

#include "Components/GameplayTagsComponent.h"

UGameplayTagsComponent::UGameplayTagsComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}
