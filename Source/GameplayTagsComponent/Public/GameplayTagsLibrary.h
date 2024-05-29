// Copyright (c) 2003-2023 Rionix, Ltd. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsLibrary.generated.h"

UCLASS()
class UGameplayTagsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Statics

    static class UGameplayTagsComponent* Get(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Reset Gameplay Tags in Component"))
    static void ResetGameplayTags(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Set Gameplay Tags in Component"))
    static void SetGameplayTags(AActor* Actor, FGameplayTagContainer Tags);

    UFUNCTION(BlueprintPure, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Get Gameplay Tags from Component"))
    static FGameplayTagContainer GetGameplayTags(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Add Gameplay Tag in Component"))
    static void AddGameplayTag(AActor* Actor, FGameplayTag Tag);

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Append Gameplay Tags in Component"))
    static void AppendGameplayTags(AActor* Actor, FGameplayTagContainer Tags);

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Remove Gameplay Tag from Component"))
    static void RemoveGameplayTag(AActor* Actor, FGameplayTag Tag, bool bExactMatch = true);

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Remove Gameplay Tags from Component"))
    static void RemoveGameplayTags(AActor* Actor, FGameplayTagContainer Tags, bool bExactMatch = true);
   
    UFUNCTION(BlueprintPure, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Has Gameplay Tag in Component"))
    static bool HasGameplayTag(AActor* Actor, FGameplayTag Tag, bool bExactMatch);

    UFUNCTION(BlueprintPure, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Has Any Gameplay Tags in Component"))
    static bool HasAnyGameplayTags(AActor* Actor, FGameplayTagContainer Tags, bool bExactMatch);

    UFUNCTION(BlueprintPure, Category = "GameplayTags|TagsComponent", meta = (DisplayName = "Has All Gameplay Tags in Component"))
    static bool HasAllGameplayTags(AActor* Actor, FGameplayTagContainer Tags, bool bExactMatch);

    UFUNCTION(BlueprintCallable, Category = "GameplayTags|TagsComponent", meta = (WorldContext = "WorldContextObject"))
    static void GetAllActorsWithGameplayTags(const UObject* WorldContextObject,
        FGameplayTagContainer Tags, TArray<AActor*>& OutActors);
};
