---
layout: page
title: Documentation
permalink: /problems/
feedback: false
---

# 전체 목록

모든 글 보기

<div class="section-index">
    <hr class="panel-line">
    {% for post in site.docs  %}        
    <font style="font-size: 15px;"><b><a href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a></b></font><br>
    {% endfor %}
    <!-- {% for post in site.docs  %}        
    <div class="entry">
    <h5><a href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a></h5>
    <p>{{ post.description }}</p>
    </div>{% endfor %} -->
</div>
