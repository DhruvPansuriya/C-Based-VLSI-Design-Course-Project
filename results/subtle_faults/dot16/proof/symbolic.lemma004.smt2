; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x725246 (bvmul arg0_6 arg1_7)))
(let ((?x721638 (bvmul (_ bv4294967295 32) ?x725246)))
(let ((?x717865 (bvmul arg0_7 arg1_7)))
(let ((?x19099 (bvadd ?x717865 ?x721638)))
(and (distinct ?x19099 (_ bv0 32)) true))))))
(check-sat)
