// Copyright (c) 2003-2023 rionix. All Rights Reserved.

using UnrealBuildTool;

public class GameplayTagsComponent : ModuleRules
{
	public GameplayTagsComponent(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core" });
		PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "GameplayTags" });
	}
}
