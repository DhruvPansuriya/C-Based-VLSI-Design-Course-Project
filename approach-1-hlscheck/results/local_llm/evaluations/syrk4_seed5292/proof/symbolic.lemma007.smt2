; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x4140 (bvmul arg0_0 arg0_2)))
(let ((?x21842 (bvmul (_ bv4294967295 32) ?x4140)))
(let ((?x229 (bvmul arg0_0 arg0_8)))
(let ((?x4148 (bvadd ?x229 ?x21842)))
(and (distinct ?x4148 (_ bv0 32)) true))))))
(check-sat)
