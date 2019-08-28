#ifndef UIELEMENTS_H
#define UIELEMENTS_H

struct UIElement
{
	crcs_t hash;
	int refCount;
	void (*RenderFn)(UIElement*);

	void Render()
	{
		RenderFn(this);
	}
};

struct UIColumn
{
	std::vector<crcs_t> elementHashes;
	std::vector<UIElement*> elements;

	UIColumn() = default;

	template<typename...  Args>
	UIColumn(Args... args)
		: UIColumn()
	{
		ConstructHashList(args...);
	}

	~UIColumn()
	{
		for (UIElement*& el : elements)
			el->refCount--;
	}

	template<typename Q>
	void PushToHashList(const Q& arg)
	{
		elementHashes.push_back(Q::CRCVAL);
	}

	template<>
	void PushToHashList<crcs_t>(const crcs_t& crc)
	{
		elementHashes.push_back(crc);
	}

	template<typename Q>
	void ConstructHashList(const Q& arg)
	{
		PushToHashList(arg);
	}

	template<typename Q, typename... Args>
	void ConstructHashList(const Q& arg, Args... args)
	{
		PushToHashList(arg);
		ConstructHashList(args...);
	}

	template<typename iterator_type>
	void Initialize(iterator_type begin, iterator_type end, bool force = false)
	{
		if (!force && elements.size())
			return;

		for (UIElement*& el : elements)
			el->refCount--;

		elements.clear();

		for (crcs_t i : elementHashes) {
			for (iterator_type el = begin; el != end; el++) {
				if (el->hash == i) {
					el->refCount++;
					elements.push_back(&*el);
					break;
				}
			}
		}
	}

	void Render()
	{
		for (UIElement*& i : elements)
			i->Render();
	}
};

namespace UIElements
{
	template<typename iterator_type>
	static void RenderColumns(iterator_type begin, iterator_type end)
	{
		size_t sz = std::distance(begin, end);

		if (!sz)
			return;

		ImGui::Columns(sz, nullptr, false);

		begin->Render();

		for (auto it = begin + 1; it != end; it++) {
			ImGui::NextColumn();
			it->Render();
		}
	}

	template<typename iterator_type1, typename iterator_type2>
	static void InitializeColumns(iterator_type1 colBegin, iterator_type1 colEnd, iterator_type2 elementListBegin, iterator_type2 elementListEnd)
	{
		for (iterator_type1 it = colBegin; it != colEnd; it++)
			it->Initialize(elementListBegin, elementListEnd);
	}
}

#endif