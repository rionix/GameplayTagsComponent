// Copyright (c) 2003-2023 Rionix, Ltd. All Rights Reserved.

#include "GameplayTagsLibrary.h"
#include "Components/GameplayTagsComponent.h"

#include "Engine/Engine.h"
#include "EngineUtils.h"

UGameplayTagsComponent* UGameplayTagsLibrary::Get(AActor* Actor)
{
    return IsValid(Actor) ? Actor->FindComponentByClass<UGameplayTagsComponent>() : nullptr;
}

void UGameplayTagsLibrary::ResetGameplayTags(AActor* Actor)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        Component->Reset();
}

void UGameplayTagsLibrary::SetGameplayTags(AActor* Actor, FGameplayTagContainer Tags)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        Component->GameplayTags = Tags;
}

FGameplayTagContainer UGameplayTagsLibrary::GetGameplayTags(AActor* Actor)
{
    UGameplayTagsComponent* Component = Get(Actor);
    return Component ? Component->GameplayTags : FGameplayTagContainer{};
}

void UGameplayTagsLibrary::AddGameplayTag(AActor* Actor, FGameplayTag Tag)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        Component->GameplayTags.AddTag(Tag);
}

void UGameplayTagsLibrary::AppendGameplayTags(AActor* Actor, FGameplayTagContainer Tags)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        Component->GameplayTags.AppendTags(Tags);
}

void UGameplayTagsLibrary::RemoveGameplayTag(AActor* Actor, FGameplayTag Tag)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        Component->GameplayTags.RemoveTag(Tag);
}

void UGameplayTagsLibrary::RemoveGameplayTags(AActor* Actor, FGameplayTagContainer Tags)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        Component->GameplayTags.RemoveTags(Tags);
}

bool UGameplayTagsLibrary::HasGameplayTag(AActor* Actor, FGameplayTag Tag, bool bExactMatch)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        return bExactMatch ? Component->GameplayTags.HasTagExact(Tag) : Component->GameplayTags.HasTag(Tag);
    return false;
}

bool UGameplayTagsLibrary::HasAnyGameplayTags(AActor* Actor, FGameplayTagContainer Tags, bool bExactMatch)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        return bExactMatch ? Component->GameplayTags.HasAnyExact(Tags) : Component->GameplayTags.HasAny(Tags);
    return false;
}

bool UGameplayTagsLibrary::HasAllGameplayTags(AActor* Actor, FGameplayTagContainer Tags, bool bExactMatch)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        return bExactMatch ? Component->GameplayTags.HasAllExact(Tags) : Component->GameplayTags.HasAll(Tags);
    return false;
}

void UGameplayTagsLibrary::GetAllActorsWithGameplayTags(const UObject* WorldContextObject,
    FGameplayTagContainer Tags, TArray<AActor*>& OutActors)
{
    OutActors.Reset();

    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
    if (World && Tags.IsValid())
    {
        for (FActorIterator It(World); It; ++It)
            if (HasAnyGameplayTags(*It, Tags, false))
                OutActors.Add(*It);
    }
}
