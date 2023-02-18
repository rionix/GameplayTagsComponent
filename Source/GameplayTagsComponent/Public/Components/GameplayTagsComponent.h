// Copyright (c) 2003-2023 Rionix, Ltd. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsComponent.generated.h"

UCLASS(ClassGroup= "Custom", meta = (BlueprintSpawnableComponent))
class UGameplayTagsComponent : public UActorComponent
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags")
    FGameplayTagContainer GameplayTags;

public:

    UGameplayTagsComponent();

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent")
    void Reset() { GameplayTags.Reset(); }

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent")
    void AddTag(FGameplayTag Tag) { GameplayTags.AddTag(Tag); }

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent")
    void AppendTags(FGameplayTagContainer Tags) { GameplayTags.AppendTags(Tags); }

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent")
    void RemoveTag(FGameplayTag Tag) { GameplayTags.RemoveTag(Tag); }

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent")
    void RemoveTags(FGameplayTagContainer Tags) { GameplayTags.RemoveTags(Tags); }

    UFUNCTION(BlueprintPure, Category = "GameplayTags|TagsComponent")
    bool HasTag(FGameplayTag Tag, bool bExactMatch = false) const 
    { 
        return bExactMatch ? GameplayTags.HasTagExact(Tag) : GameplayTags.HasTag(Tag);
    }

    UFUNCTION(BlueprintPure, Category = "GameplayTags|TagsComponent")
    bool HasAnyTags(FGameplayTagContainer Tags, bool bExactMatch = false) const 
    { 
        return bExactMatch ? GameplayTags.HasAnyExact(Tags) : GameplayTags.HasAny(Tags); 
    }

    UFUNCTION(BlueprintPure, Category = "GameplayTags|TagsComponent")
    bool HasAllTags(FGameplayTagContainer Tags, bool bExactMatch = false) const 
    { 
        return bExactMatch ? GameplayTags.HasAllExact(Tags) : GameplayTags.HasAll(Tags);
    }
};
