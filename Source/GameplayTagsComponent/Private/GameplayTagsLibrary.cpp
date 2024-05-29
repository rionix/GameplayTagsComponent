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
        Component->AddTag(Tag);
}

void UGameplayTagsLibrary::AppendGameplayTags(AActor* Actor, FGameplayTagContainer Tags)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        Component->AppendTags(Tags);
}

void UGameplayTagsLibrary::RemoveGameplayTag(AActor* Actor, FGameplayTag Tag, bool bExactMatch)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        Component->RemoveTag(Tag, bExactMatch);
}

void UGameplayTagsLibrary::RemoveGameplayTags(AActor* Actor, FGameplayTagContainer Tags, bool bExactMatch)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        Component->RemoveTags(Tags, bExactMatch);
}

bool UGameplayTagsLibrary::HasGameplayTag(AActor* Actor, FGameplayTag Tag, bool bExactMatch)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        return Component->HasTag(Tag, bExactMatch);
    return false;
}

bool UGameplayTagsLibrary::HasAnyGameplayTags(AActor* Actor, FGameplayTagContainer Tags, bool bExactMatch)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        return Component->HasAnyTags(Tags, bExactMatch);
    return false;
}

bool UGameplayTagsLibrary::HasAllGameplayTags(AActor* Actor, FGameplayTagContainer Tags, bool bExactMatch)
{
    if (UGameplayTagsComponent* Component = Get(Actor))
        return Component->HasAllTags(Tags, bExactMatch);
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
