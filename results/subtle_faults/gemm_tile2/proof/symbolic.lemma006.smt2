; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x425916 (bvmul arg0_1 arg1_6)))
(let ((?x491443 (bvmul (_ bv4294967295 32) ?x425916)))
(let ((?x22849 (bvmul arg0_1 arg1_7)))
(let ((?x158617 (bvadd ?x22849 ?x491443)))
(and (distinct ?x158617 (_ bv0 32)) true))))))
(check-sat)
