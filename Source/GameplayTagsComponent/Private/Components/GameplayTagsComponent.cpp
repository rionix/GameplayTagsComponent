// Copyright (c) 2003-2023 Rionix, Ltd. All Rights Reserved.

#include "Components/GameplayTagsComponent.h"

UGameplayTagsComponent::UGameplayTagsComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UGameplayTagsComponent::RemoveTag(FGameplayTag Tag, bool bExactMatch)
{
    if (bExactMatch)
        GameplayTags.RemoveTag(Tag);
    else
    {
        const FGameplayTagContainer OtherContainer{ Tag };
        GameplayTags.RemoveTags(GameplayTags.Filter(OtherContainer));
    }
}

void UGameplayTagsComponent::RemoveTags(FGameplayTagContainer Tags, bool bExactMatch)
{
    if (bExactMatch)
        GameplayTags.RemoveTags(Tags);
    else
        GameplayTags.RemoveTags(GameplayTags.Filter(Tags));
}
