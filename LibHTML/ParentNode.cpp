#include <LibHTML/ParentNode.h>

void ParentNode::append_child(Retained<Node> node)
{
    if (m_last_child)
        m_last_child->set_next_sibling(node.ptr());
    m_last_child = &node.leak_ref();
    if (!m_first_child)
        m_first_child = m_last_child;
}
