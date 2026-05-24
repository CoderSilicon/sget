<script>
	const footerSections = [
		{
			id: 'product-menu',
			title: 'Product',
			links: [
				{ id: 'downloads', name: 'Downloads', href: '#' },
				{ id: 'documentation', name: 'Documentation', href: '#' },
				{ id: 'changelog', name: 'Changelog', href: '#' }
			]
		},
		{
			id: 'resources-menu',
			title: 'Resources',
			links: [
				{ id: 'about', name: 'About', href: '#' },
				{ id: 'blog', name: 'Blog', href: '#' },
				{ id: 'community', name: 'Community', href: '#' }
			]
		}
	];

	// Social connection links with SVG paths
	const socialLinks = [
		{
			id: 'github',
			href: '#',
			aria: 'GitHub',
			iconPath:
				'<path d="M12 2C6.477 2 2 6.484 2 12.017c0 4.425 2.865 8.18 6.839 9.504.5.092.682-.217.682-.483 0-.237-.008-.868-.013-1.703-2.782.605-3.369-1.343-3.369-1.343-.454-1.158-1.11-1.466-1.11-1.466-.908-.62.069-.608.069-.608 1.003.07 1.531 1.032 1.531 1.032.892 1.53 2.341 1.088 2.91.832.092-.647.35-1.088.636-1.338-2.22-.253-4.555-1.113-4.555-4.951 0-1.093.39-1.988 1.029-2.688-.103-.253-.446-1.272.098-2.65 0 0 .84-.27 2.75 1.026A9.564 9.564 0 0112 6.844c.85.004 1.705.115 2.504.337 1.909-1.296 2.747-1.027 2.747-1.027.546 1.379.202 2.398.1 2.651.64.7 1.028 1.595 1.028 2.688 0 3.848-2.339 4.695-4.566 4.943.359.309.678.92.678 1.855 0 1.338-.012 2.419-.012 2.747 0 .268.18.58.688.482A10.019 10.019 0 0022 12.017C22 6.484 17.522 2 12 2z"/>'
		},
		{
			id: 'twitter',
			href: '#',
			aria: 'Twitter',
			iconPath:
				'<path d="M18.244 2.25h3.308l-7.227 8.26 8.502 11.24H16.17l-5.214-6.817L4.99 21.75H1.68l7.73-8.835L1.254 2.25H8.08l4.713 6.231zm-1.161 17.52h1.833L7.084 4.126H5.117z"/>'
		}
	];
</script>
<section
	class="flex flex-col items-center border-t border-white/5 bg-[#18181B] px-6 pt-32 pb-16 font-mono text-white selection:bg-[#00f5c4]/30 md:px-12"
>
	<footer
		class="grid w-full max-w-6xl grid-cols-1 items-start gap-10 md:grid-cols-2 lg:grid-cols-12 lg:gap-4"
	>
		<div class="space-y-4 lg:col-span-5">
			<div class="text-base font-bold tracking-tight">
				<span class="mr-0.5 text-[#00f5c4]">&gt;_</span> sget
			</div>
			<p class="max-w-xs text-xs leading-relaxed text-[#8e929a] md:text-sm">
				A CLI for extracting data from websites. Like curl, but better.
			</p>
		</div>

		{#each footerSections as section (section.id)}
			<div class="space-y-4 lg:col-span-2">
				<h3 class="text-[0.68rem] font-bold tracking-widest text-[#545861] uppercase">
					{section.title}
				</h3>
				<ul class="space-y-2.5 text-xs md:text-sm">
					{#each section.links as link (link.id)}
						<li>
							<a class="text-[#8e929a] transition-colors hover:text-white">
								{link.name}
							</a>
						</li>
					{/each}
				</ul>
			</div>
		{/each}

		<div class="space-y-4 lg:col-span-3">
			<h3 class="text-[0.68rem] font-bold tracking-widest text-[#545861] uppercase">Connect</h3>
			<div class="flex items-center gap-4 text-[#8e929a]">
				{#each socialLinks as social (social.id)}
					<a aria-label={social.aria} class="transition-colors hover:text-white">
						<svg class="h-[18px] w-[18px]" fill="currentColor" viewBox="0 0 24 24">
							{@html social.iconPath}
						</svg>
					</a>
				{/each}
			</div>
		</div>
	</footer>
</section>